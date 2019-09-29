/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:06:38 by mlantonn          #+#    #+#             */
/*   Updated: 2019/09/27 14:14:29 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "block.h"

void	get_initial_blocks(t_blocks *b, const t_vec *ray,
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

static int	hit(t_e *e, t_line *line, const t_vec *ray, t_pos *pos)
{
	t_blocks	blocks;
	t_block		*b;
	_Bool		y_axis;

	get_initial_blocks(&blocks, ray, &e->cam.pos, pos);
	line->block_hit = NULL;
	while (1)
	{
		if (blocks.total.x < blocks.total.y)
		{
			blocks.total.x += blocks.one.x;
			pos->x += ray->x < 0 ? -1 : 1;
			y_axis = 0;
		}
		else
		{
			blocks.total.y += blocks.one.y;
			pos->y += ray->y < 0 ? -1 : 1;
			y_axis = 1;
		}
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

static void	process_ray(t_e *e, t_vec ray, t_pos pos, int x)
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
	draw_line(e, line, hit_pos, ray);
}

void		*draw_thread(void *arg)
{
	pthread_t	current;
	t_e			*e;
	t_vec		ray;
	int			x;
	int			i;

	current = pthread_self();
	e = (t_e *)arg;
	i = 0;
	while (current != e->thread[i])
		++i;
	x = i * e->sdl.w / NB_THR - 1;
	i = (i + 1) * e->sdl.w / NB_THR;
	while (++x < i)
	{
		ray = vec_add(e->cam.dir,
			vec_multiply(e->cam.plane, 1 - (x / (double)(e->sdl.w / 2))));
		process_ray(e, ray, e->cam.pos_i, x);
	}
	pthread_exit(NULL);
}

_Bool		raycasting(t_e *e)
{
	int			i;
	int			j;

	i = -1;
	while (++i < NB_THR)
	{
		if (pthread_create(&e->thread[i], NULL, &draw_thread, e))
		{
			ft_dprintf(2, "Could not create needed thread(s): %s\n",
				strerror(errno));
			j = -1;
			while (++j < i)
				pthread_cancel(e->thread[j]);
			return (EXIT_FAILURE);
		}
	}
	i = -1;
	while (++i < NB_THR)
		pthread_join(e->thread[i], NULL);
	print_tex(&e->sdl);
	return (EXIT_SUCCESS);
}
