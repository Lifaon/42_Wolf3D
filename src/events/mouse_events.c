/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:49:37 by mlantonn          #+#    #+#             */
/*   Updated: 2019/09/26 17:29:49 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void	mouse_event(t_e *e, SDL_Event ev)
{
	static _Bool	key_downs[4] = (_Bool[4]){0, 1, 0, 0};
	int				center;
	int				cursor;

	if (e->show_cursor)
		return ;
	center = e->sdl.w / 2;
	cursor = ev.motion.x;
	if (cursor == center)
		return ;
	rotate(e, (double)(cursor - center) / ((double)e->sdl.w / 95.0), key_downs);
	SDL_WarpMouseInWindow(e->sdl.win, e->sdl.w / 2, e->sdl.h / 2);
}
