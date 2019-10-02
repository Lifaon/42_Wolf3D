/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:06:38 by mlantonn          #+#    #+#             */
/*   Updated: 2019/09/30 10:51:15 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "block.h"

static void		get_initial_blocks(t_blocks *b, const t_vec *ray,
		const t_vec *cam_pos, const t_pos *pos)
{
	b->one.x = fabs(1 / ray->x);
	b->one.y = fabs(1 / ray->y);
	b->total = b->one;
	if (ray->x < 0)
		b->total.x *= cam_pos->x - (double)(pos->x);
	else
		b->total.x *= (double)(pos->x + 1) - cam_pos->x;
	if (ray->y < 0)
		b->total.y *= cam_pos->y - (double)(pos->y);
	else
		b->total.y *= (double)(pos->y + 1) - cam_pos->y;
}

static _Bool	add_one_block(t_blocks *b, const t_vec *ray, t_pos *pos)
{
	if (b->total.x < b->total.y)
	{
		b->total.x += b->one.x;
		pos->x += ray->x < 0 ? -1 : 1;
		return (0);
	}
	b->total.y += b->one.y;
	pos->y += ray->y < 0 ? -1 : 1;
	return (1);
}

static int		hit(t_e *e, t_line *line, const t_vec *ray, t_pos *pos)
{
	t_blocks	blocks;
	t_block		*b;
	_Bool		y_axis;

	get_initial_blocks(&blocks, ray, &e->cam.pos, pos);
	line->block_hit = NULL;
	while (1)
	{
		y_axis = add_one_block(&blocks, ray, pos);
		if (pos->x < 0 || pos->x >= (int)e->map->x
				|| pos->y < 0 || pos->y >= (int)e->map->y)
			return (NONE);
		b = block_get(e->map->map[pos->y][pos->x]);
		if (b == NULL || b->type == T_BL_WALL)
		{
			line->block_hit = (void *)b;
			break ;
		}
	}
	if (y_axis)
		return (ray->y < 0 ? NORD : SUD);
	return (ray->x < 0 ? OUEST : EST);
}

void			process_ray(t_e *e, t_vec ray, t_pos pos, int x)
{
	t_line		line;
	double		ray_len;
	t_vec		hit_pos;

	line.x = x;
	line.cardinal = hit(e, &line, &ray, &pos);
	ray_len = 0.0;
	if (line.cardinal == NORD || line.cardinal == SUD)
		ray_len = (((double)(pos.y + (ray.y < 0)) - e->cam.pos.y) / ray.y);
	else if (line.cardinal == OUEST || line.cardinal == EST)
		ray_len = (((double)(pos.x + (ray.x < 0)) - e->cam.pos.x) / ray.x);
	line.height = ray_len == 0.0 ? 0 : abs((int)((double)(e->sdl.h) / ray_len));
	hit_pos = vec_add(vec_multiply(ray, ray_len), e->cam.pos);
	if (line.cardinal == OUEST || line.cardinal == EST)
		line.wall_x = hit_pos.y - floor(hit_pos.y);
	else
		line.wall_x = hit_pos.x - floor(hit_pos.x);
	line.wall_x = (line.cardinal == SUD || line.cardinal == OUEST)
		? 1.0 - line.wall_x : line.wall_x;
	draw_line(e, line, hit_pos);
}
