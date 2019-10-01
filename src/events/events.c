/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:23:56 by mlantonn          #+#    #+#             */
/*   Updated: 2019/10/01 10:44:18 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

static _Bool	limit_frames(t_e *e)
{
	static unsigned int	last_fps = 17;
	static unsigned int	last_time = 0;
	static unsigned int	current_time;

	current_time = SDL_GetTicks();
	if (current_time < last_time + 16)
		return (1);
	e->fps = ((1000 / (current_time - last_time)) + last_fps) / 2;
	last_fps = e->fps;
	last_time = current_time;
	ft_printf("\rfps:%-3d", e->fps);
	return (0);
}

_Bool			event_loop(t_e *e)
{
	static _Bool	key_downs[6] = (_Bool[6]){0, 0, 0, 0, 0, 0};
	SDL_Event		ev;

	while (1)
	{
		if (limit_frames(e))
			continue ;
		while (SDL_PollEvent(&ev))
		{
			if (ev.type == SDL_QUIT || (ev.type == SDL_KEYDOWN
				&& ev.key.keysym.sym == SDLK_ESCAPE))
				return (EXIT_SUCCESS);
			if (ev.type == SDL_KEYDOWN || ev.type == SDL_KEYUP)
				key_event(e, key_downs, ev);
			if (ev.type == SDL_MOUSEMOTION)
				mouse_event(e, ev);
			if (ev.type == SDL_WINDOWEVENT && window_event(e, ev))
				return (EXIT_FAILURE);
		}
		if (update_cam(e, key_downs))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
