/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_cam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 12:10:48 by mlantonn          #+#    #+#             */
/*   Updated: 2019/10/01 10:24:24 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "block.h"

static void		clipping(t_e *e, t_vec pos, _Bool moved[2])
{
	t_block	*block;
	t_pos	pos_i;

	pos_i.x = pos.x < 0.0 ? -1 : (int)pos.x;
	pos_i.y = pos.y < 0.0 ? -1 : (int)pos.y;
	if (pos_i.x >= 0 && pos_i.x < (int)e->map->x)
	{
		block = block_get(e->map->map[e->cam.pos_i.y][pos_i.x]);
		moved[0] = (block != NULL && block->type == T_BL_VOID);
	}
	if (pos_i.y >= 0 && pos_i.y < (int)e->map->y)
	{
		block = block_get(e->map->map[pos_i.y][e->cam.pos_i.x]);
		moved[1] = (block != NULL && block->type == T_BL_VOID);
	}
	if (moved[0] && moved[1])
	{
		block = block_get(e->map->map[pos_i.y][pos_i.x]);
		moved[0] = block != NULL && block->type == T_BL_VOID;
		moved[1] = block != NULL && block->type == T_BL_VOID;
	}
}

static t_vec	get_moving_dir(t_e *e, _Bool key_downs[6])
{
	double	coeff;
	t_vec	dirs[4];
	t_vec	dir;

	coeff = 2.5;
	dirs[0] = vec_multiply(e->cam.dir, 1 * (double)key_downs[W]);
	dirs[1] = vec_multiply(e->cam.dir, -1 * (double)key_downs[S]);
	dirs[2] = vec_multiply(e->cam.plane, 1 * (double)key_downs[A]);
	dirs[3] = vec_multiply(e->cam.plane, -1 * (double)key_downs[D]);
	dir = vec_add(vec_add(dirs[0], dirs[1]), vec_add(dirs[2], dirs[3]));
	dir = vec_normalize(dir);
	dir = vec_multiply(dir, (e->fps ? coeff / (double)e->fps : 0));
	return (dir);
}

static void		move(t_e *e, _Bool key_downs[6])
{
	_Bool	moved[2];
	_Bool	moved_far[2];
	t_vec	pos;
	t_vec	dir;

	dir = get_moving_dir(e, key_downs);
	if (dir.x == 0.0 && dir.y == 0.0)
		return ;
	pos = vec_add(e->cam.pos, dir);
	clipping(e, pos, moved);
	clipping(e, vec_add(e->cam.pos, vec_multiply(dir, 4)), moved_far);
	if (moved[0] && moved_far[0])
	{
		e->cam.pos.x = pos.x;
		e->cam.pos_i.x = (int)pos.x;
	}
	if (moved[1] && moved_far[1])
	{
		e->cam.pos.y = pos.y;
		e->cam.pos_i.y = (int)pos.y;
	}
}

void			rotate(t_e *e, double angle, _Bool key_downs[6])
{
	t_vec	dir;
	t_vec	plane;
	double	theta;

	if (key_downs[LEFT] == key_downs[RIGHT])
		return ;
	dir = e->cam.dir;
	plane = e->cam.plane;
	theta = angle / 180.0 * M_PI;
	if (key_downs[LEFT])
		theta = -theta;
	e->cam.dir.x = dir.x * cos(theta) - dir.y * sin(theta);
	e->cam.dir.y = dir.x * sin(theta) + dir.y * cos(theta);
	e->cam.plane.x = plane.x * cos(theta) - plane.y * sin(theta);
	e->cam.plane.y = plane.x * sin(theta) + plane.y * cos(theta);
}

_Bool			update_cam(t_e *e, _Bool key_downs[6])
{
	move(e, key_downs);
	rotate(e, e->fps ? 180 / (double)e->fps : 0, key_downs);
	return (raycasting(e));
}
