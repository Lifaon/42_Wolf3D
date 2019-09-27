/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:11:17 by mlantonn          #+#    #+#             */
/*   Updated: 2019/09/27 11:28:30 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static _Bool	is_outline(t_e *e, t_line line, t_vec hit)
{
	if (!e->outlines)
		return (0);
	hit.x -= (double)(int)hit.x;
	hit.x *= hit.x < 0 ? -1 : 1;
	hit.y -= (double)(int)hit.y;
	hit.y *= hit.y < 0 ? -1 : 1;
	if (((line.cardinal == NORD || line.cardinal == SUD)
		&& (hit.x <= 0.01 || hit.x >= 0.99))
		|| ((line.cardinal == OUEST || line.cardinal == EST)
		&& (hit.y <= 0.01 || hit.y >= 0.99)))
		return (1);
	return (0);
}

void			draw_line(t_e *e, t_line line, t_vec hit)
{
	static t_col	wall[5] = (t_col[5]){{0x023788}, {0x920075}, {0x650D89},
													{0xD40078}, {0x0}};
	_Bool	darken;
	int		index[4];
	int		y;
	int		width;

	darken = is_outline(e, line, hit);
	width = e->outlines * (1 + line.height / 75);
	index[1] = (e->sdl.h - line.height) / 2;
	index[0] = index[1] - width;
	index[2] = (e->sdl.h + line.height) / 2;
	index[3] = index[2] + width;
	y = 0;
	while (y < e->sdl.h && y < index[0])
		put_pixel(&e->sdl, (t_col){0x0}, line.x, y++);
	while (y < e->sdl.h && y < index[1])
		put_pixel(&e->sdl, wall[NONE], line.x, y++);
	while (y < e->sdl.h && y < index[2])
		put_pixel(&e->sdl, darken ? wall[NONE] :
			wall[line.cardinal], line.x, y++);
	while (y < e->sdl.h && y < index[3])
		put_pixel(&e->sdl, wall[NONE], line.x, y++);
	while (y < e->sdl.h)
		put_pixel(&e->sdl, (t_col){0x2E2157}, line.x, y++);
}
