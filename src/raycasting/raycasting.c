/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:06:38 by mlantonn          #+#    #+#             */
/*   Updated: 2019/09/27 11:27:14 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static int	hit(t_e *e, t_blocks blocks, t_vec ray, t_pos *pos)
{
	_Bool	y_axis;

	while (1)
	{
		if (blocks.total.x < blocks.total.y)
		{
			blocks.total.x += blocks.one.x;
			pos->x += ray.x < 0 ? -1 : 1;
			y_axis = 0;
		}
		else
		{
			blocks.total.y += blocks.one.y;
			pos->y += ray.y < 0 ? -1 : 1;
			y_axis = 1;
		}
		if (pos->x < 0 || pos->x >= e->map.x
			|| pos->y < 0 || pos->y >= e->map.y)
			return (NONE);
		if (e->map.str[pos->x + pos->y * e->map.x] == '1')
			break ;
	}
	if (y_axis)
		return (ray.y < 0 ? NORD : SUD);
	return (ray.x < 0 ? OUEST : EST);
}

static void	process_ray(t_e *e, t_vec ray, t_pos pos, int x)
{
	t_blocks	blocks;
	t_line		line;
	double		ray_len;

	line.x = x;
	blocks.one.x = fabs(1 / ray.x);
	blocks.one.y = fabs(1 / ray.y);
	blocks.total = blocks.one;
	if (ray.x < 0)
		blocks.total.x *= e->cam.pos.x - (double)(pos.x);
	else
		blocks.total.x *= (double)(pos.x + 1) - e->cam.pos.x;
	if (ray.y < 0)
		blocks.total.y *= e->cam.pos.y - (double)(pos.y);
	else
		blocks.total.y *= (double)(pos.y + 1) - e->cam.pos.y;
	line.cardinal = hit(e, blocks, ray, &pos);
	ray_len = 0.0;
	if (line.cardinal == NORD || line.cardinal == SUD)
		ray_len = (((double)(pos.y + (ray.y < 0)) - e->cam.pos.y) / ray.y);
	else if (line.cardinal == OUEST || line.cardinal == EST)
		ray_len = (((double)(pos.x + (ray.x < 0)) - e->cam.pos.x) / ray.x);
	line.height = ray_len == 0.0 ? 0 : abs((int)((double)(e->sdl.h) / ray_len));
	draw_line(e, line, vec_add(vec_multiply(ray, ray_len), e->cam.pos));
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
