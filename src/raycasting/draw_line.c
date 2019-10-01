/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:11:17 by mlantonn          #+#    #+#             */
/*   Updated: 2019/10/01 14:47:43 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "block.h"
#include "singletone.h"
#include "texture.h"

static _Bool	is_outline(t_e *e, t_line line, t_vec hit)
{
	if (!e->outlines || line.cardinal == NONE)
		return (0);
	hit.x -= (double)(int)hit.x;
	hit.y -= (double)(int)hit.y;
	hit.x *= hit.x < 0 ? -1 : 1;
	hit.y *= hit.y < 0 ? -1 : 1;
	if (((line.cardinal == NORD || line.cardinal == SUD)
		&& (hit.x <= 0.01 || hit.x >= 0.99))
		|| ((line.cardinal == OUEST || line.cardinal == EST)
		&& (hit.y <= 0.01 || hit.y >= 0.99)))
		return (1);
	return (0);
}

static void		draw_sky(t_e *e, t_line line, int index)
{
	double	win_ratio;
	double	angle;
	int		y;
	t_pos	px;

	y = -1;
	if (!e->skybox || index == 0)
	{
		while (++y < index && y < e->sdl.h)
			put_pixel(&e->sdl, (t_col){0x0}, line.x, y);
		return ;
	}
	win_ratio = (double)(e->sky.h) / (double)(e->sdl.h / 2);
	angle = (M_PI + atan2(-e->cam.plane.y, -e->cam.plane.x)) / (M_PI * 2);
	angle -= (double)(e->sdl.w / 2 - line.x) / (e->sdl.w * 2);
	if (angle < 0.0 || angle >= 1.0)
		angle += angle < 0.0 ? 1.0 : -1.0;
	px.x = ((double)e->sky.w * angle);
	while (++y < index && y < e->sdl.h)
	{
		px.y = (int)((double)(y) * win_ratio);
		put_pixel(&e->sdl, e->sky.arr[px.x + px.y * e->sky.w], line.x, y);
	}
}

static void		prepare_texture(t_texture *t[4], const t_block *b)
{
	t_texture	**meta;

	if (b == NULL)
		return ;
	meta = *singletone_texture();
	t[NORD] = meta[b->tex_north];
	t[SUD] = meta[b->tex_south];
	t[OUEST] = meta[b->tex_west];
	t[EST] = meta[b->tex_east];
}

static void		draw_wall(t_e *e, t_line line, int min, int max, _Bool darken)
{
	t_texture	*tex[4];
	int			y;
	double		py;
	double		tex_coeff;

	prepare_texture(tex, line.block_hit);
	tex_coeff = (double)(max - min);
	y = min - 1;
	while (++y < e->sdl.h && y < max)
	{
		if (darken || line.block_hit == NULL)
			put_pixel(&e->sdl, (t_col){0x0}, line.x, y);
		else
		{
			py = (double)(y - min) / tex_coeff;
			put_pixel(&e->sdl, texture_get_color(tex[line.cardinal],
				py, line.wall_x), line.x, y);
		}
	}
}

void			draw_line(t_e *e, t_line line, t_vec hit)
{
	_Bool		darken;
	int			index[4];
	int			y;
	int			width;

	darken = is_outline(e, line, hit);
	width = line.cardinal != NONE ? e->outlines * (1 + line.height / 75) : 0;
	index[1] = (e->sdl.h - line.height) / 2;
	index[0] = index[1] - width;
	index[2] = (e->sdl.h + line.height) / 2;
	index[3] = index[2] + width;
	y = index[0];
	draw_sky(e, line, index[0]);
	while (y < e->sdl.h && y < index[1])
		put_pixel(&e->sdl, (t_col){0x0}, line.x, y++);
	y = index[2];
	draw_wall(e, line, index[1], index[2], darken);
	while (y < e->sdl.h && y < index[3])
		put_pixel(&e->sdl, (t_col){0x0}, line.x, y++);
	while (y < e->sdl.h)
		put_pixel(&e->sdl, (t_col){0x2E2157}, line.x, y++);
}
