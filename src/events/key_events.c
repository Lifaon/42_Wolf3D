/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:49:41 by mlantonn          #+#    #+#             */
/*   Updated: 2019/09/27 18:40:22 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

static void	toggle_cursor(t_e *e)
{
	e->show_cursor = !SDL_ShowCursor(e->show_cursor ? SDL_DISABLE : SDL_ENABLE);
	SDL_WarpMouseInWindow(e->sdl.win, e->sdl.w / 2, e->sdl.h / 2);
}

static void	toggle_fullscreen(t_e *e)
{
	static _Bool	is_fullscreen = 0;
	static int		w;
	static int		h;
	SDL_DisplayMode	dm;

	if (!is_fullscreen)
	{
		w = e->sdl.w;
		h = e->sdl.h;
		SDL_GetCurrentDisplayMode(0, &dm);
		e->sdl.w = dm.w;
		e->sdl.h = dm.h;
		SDL_SetWindowSize(e->sdl.win, e->sdl.w, e->sdl.h);
		SDL_SetWindowFullscreen(e->sdl.win, SDL_WINDOW_FULLSCREEN);
		if (e->show_cursor)
			toggle_cursor(e);
	}
	else
	{
		SDL_SetWindowFullscreen(e->sdl.win, 0);
		e->sdl.w = w;
		e->sdl.h = h;
		SDL_SetWindowSize(e->sdl.win, e->sdl.w, e->sdl.h);
	}
	is_fullscreen = !is_fullscreen;
}

static void	update_key_downs(_Bool key_downs[6], SDL_Event ev, SDL_Keycode k)
{
	if (ev.type == SDL_KEYDOWN)
	{
		key_downs[W] = (k == SDLK_UP || k == SDLK_w) ? 1 : key_downs[W];
		key_downs[S] = (k == SDLK_DOWN || k == SDLK_s) ? 1 : key_downs[S];
		key_downs[A] = k == SDLK_a ? 1 : key_downs[A];
		key_downs[D] = k == SDLK_d ? 1 : key_downs[D];
		key_downs[LEFT] = k == SDLK_LEFT ? 1 : key_downs[LEFT];
		key_downs[RIGHT] = k == SDLK_RIGHT ? 1 : key_downs[RIGHT];
	}
	else
	{
		key_downs[W] = (k == SDLK_UP || k == SDLK_w) ? 0 : key_downs[W];
		key_downs[S] = (k == SDLK_DOWN || k == SDLK_s) ? 0 : key_downs[S];
		key_downs[A] = k == SDLK_a ? 0 : key_downs[A];
		key_downs[D] = k == SDLK_d ? 0 : key_downs[D];
		key_downs[LEFT] = k == SDLK_LEFT ? 0 : key_downs[LEFT];
		key_downs[RIGHT] = k == SDLK_RIGHT ? 0 : key_downs[RIGHT];
	}
}

void		key_event(t_e *e, _Bool key_downs[6], SDL_Event ev)
{
	SDL_Keycode k;

	k = ev.key.keysym.sym;
	if (ev.type == SDL_KEYDOWN)
	{
		if (k == SDLK_TAB)
			toggle_cursor(e);
		if (k == SDLK_f)
			toggle_fullscreen(e);
		if (k == SDLK_t)
			e->outlines = !e->outlines;
		if (k == SDLK_g)
			e->skybox = !e->skybox;
	}
	update_key_downs(key_downs, ev, k);
}
