/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:49:39 by mlantonn          #+#    #+#             */
/*   Updated: 2019/10/08 11:45:18 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

static _Bool	size_changed(t_e *e, SDL_Event ev)
{
	e->sdl.w = ev.window.data1;
	e->sdl.h = ev.window.data2;
	free(e->sdl.img);
	if (!(e->sdl.img = (t_col *)malloc(sizeof(t_col) *
		e->sdl.w * e->sdl.h)))
	{
		ft_dprintf(2, "Could not allocate needed memory: %s\n",
			strerror(errno));
		return (EXIT_FAILURE);
	}
	SDL_DestroyTexture(e->sdl.tex);
	if (!(e->sdl.tex = SDL_CreateTexture(e->sdl.ren, SDL_PIXELFORMAT_BGRA32,
		SDL_TEXTUREACCESS_STREAMING, e->sdl.w, e->sdl.h)))
	{
		ft_dprintf(2, "Could not recreate SDL texture: %s\n",
			SDL_GetError());
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

_Bool			window_event(t_e *e, SDL_Event ev)
{
	if (ev.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
		return (size_changed(e, ev));
	if (ev.window.event == SDL_WINDOWEVENT_FOCUS_LOST)
		e->focus = 0;
	if (ev.window.event == SDL_WINDOWEVENT_FOCUS_GAINED)
		e->focus = 1;
	return (EXIT_SUCCESS);
}
