/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:11:17 by mlantonn          #+#    #+#             */
/*   Updated: 2019/09/26 13:16:41 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static t_col	sky = (t_col)(uint32_t)(SKY);
static t_col	ground = (t_col)(uint32_t)(GROUND);
static t_col	black = (t_col)(uint32_t)(0x0);
static t_col	wall[4] = (t_col[4]){{0x29446F}, {0x8E001C}, {0xE5D6BA}, {0xC37120}};

static _Bool	is_outline(t_line line, t_vec hit)
{
	hit.x -= (double)(int)hit.x;
	hit.x *= hit.x < 0 ? -1 : 1;
	hit.y -= (double)(int)hit.y;
	hit.y *= hit.y < 0 ? -1 : 1;
	if (((line.cardinal == NORD || line.cardinal == SUD)
		&& (hit.x < 0.01 || hit.x > 0.99))
		|| ((line.cardinal == OUEST || line.cardinal == EST)
		&& (hit.y < 0.01 || hit.y > 0.99)))
		return (1);
	return (0);
}

void			draw_line(t_e *e, t_line line, t_vec hit)
{
	_Bool	darken;
	int		index[4];
	int		y;
	int		width;

	darken = is_outline(line, hit);
	width = 1 + line.height / 75;
	index[1] = (e->sdl.h - line.height) / 2;
	index[0] = index[1] - width;
	index[2] = (e->sdl.h + line.height) / 2;
	index[3] = index[2] + width;
	y = -1;
	while (++y < e->sdl.h)
	{
		if (y < index[0])
			put_pixel(&e->sdl, sky, line.x, y);
		else if (y < index[1])
			put_pixel(&e->sdl, (t_col){0x0}, line.x, y);
		else if (y < index[2])
			put_pixel(&e->sdl, darken ? black : wall[line.cardinal], line.x, y);
		else if (y < index[3])
			put_pixel(&e->sdl, (t_col){0x0}, line.x, y);
		else
			put_pixel(&e->sdl, ground, line.x, y);
	}
}
