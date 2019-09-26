/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_cam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 12:10:48 by mlantonn          #+#    #+#             */
/*   Updated: 2019/09/26 14:05:29 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

static void		clipping(t_e *e, double coeff, _Bool moved[2])
{
	t_vec	pos;
	t_pos	pos_i;

	pos = vec_add(e->cam.pos, vec_multiply(e->cam.dir, coeff * 2));
	pos_i.x = (int)pos.x;
	pos_i.y = (int)pos.y;
	moved[0] = 0;
	moved[1] = 0;
	if ((pos_i.x == e->cam.pos_i.x) || (pos_i.x >= 0 && pos_i.x < e->map.x
		&& e->map.str[pos_i.x + e->cam.pos_i.y * e->map.x] != '1'))
		moved[0] = 1;
	if ((pos_i.y == e->cam.pos_i.y) || (pos_i.y >= 0 && pos_i.y < e->map.y
		&& e->map.str[e->cam.pos_i.x + pos_i.y * e->map.x] != '1'))
		moved[1] = 1;
}

static _Bool	move(t_e *e, _Bool key_downs[4])
{
	double	coeff;
	_Bool	moved[2];
	t_vec	pos;

	if (key_downs[UP] == key_downs[DOWN])
		return (0);
	coeff = 0.05;
	if (key_downs[DOWN])
		coeff = -coeff;
	clipping(e, coeff, moved);
	if (!moved[0] && !moved[1])
		return (0);
	pos = vec_add(e->cam.pos, vec_multiply(e->cam.dir, coeff));
	if (moved[0])
	{
		e->cam.pos.x = pos.x;
		e->cam.pos_i.x = (int)pos.x;
	}
	if (moved[1])
	{
		e->cam.pos.y = pos.y;
		e->cam.pos_i.y = (int)pos.y;
	}
	return (1);
}

_Bool			rotate(t_e *e, double angle, _Bool key_downs[4])
{
	t_vec	dir;
	t_vec	plane;
	double	theta;

	if (key_downs[LEFT] == key_downs[RIGHT])
		return (0);
	dir = e->cam.dir;
	plane = e->cam.plane;
	theta = angle / 180.0 * M_PI;
	if (key_downs[LEFT])
		theta = -theta;
	e->cam.dir.x = dir.x * cos(theta) - dir.y * sin(theta);
	e->cam.dir.y = dir.x * sin(theta) + dir.y * cos(theta);
	e->cam.plane.x = plane.x * cos(theta) - plane.y * sin(theta);
	e->cam.plane.y = plane.x * sin(theta) + plane.y * cos(theta);
	return (1);
}

_Bool			update_cam(t_e *e, _Bool key_downs[4])
{
	_Bool	rotated;
	_Bool	moved;

	rotated = rotate(e, 4.0, key_downs);
	moved = move(e, key_downs);
	if (rotated || moved || e->update)
		return (raycasting(e));
	return (EXIT_SUCCESS);
}
