/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:23:56 by mlantonn          #+#    #+#             */
/*   Updated: 2019/09/26 14:52:10 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

static void		key_event(t_e *e, _Bool key_downs[4], SDL_Event ev)
{
	SDL_Keycode k;

	k = ev.key.keysym.sym;
	if (ev.type == SDL_KEYDOWN)
	{
		if (k == SDLK_p)
		{
			e->cursor = !SDL_ShowCursor(e->cursor ? SDL_DISABLE : SDL_ENABLE);
			SDL_WarpMouseInWindow(e->sdl.win, e->sdl.w / 2, e->sdl.h / 2);
		}
		key_downs[LEFT] = k == SDLK_LEFT ? 1 : key_downs[LEFT];
		key_downs[RIGHT] = k == SDLK_RIGHT ? 1 : key_downs[RIGHT];
		key_downs[UP] = (k == SDLK_UP || k == SDLK_w) ? 1 : key_downs[UP];
		key_downs[DOWN] = (k == SDLK_DOWN || k == SDLK_s) ? 1 : key_downs[DOWN];
	}
	else
	{
		key_downs[LEFT] = k == SDLK_LEFT ? 0 : key_downs[LEFT];
		key_downs[RIGHT] = k == SDLK_RIGHT ? 0 : key_downs[RIGHT];
		key_downs[UP] = (k == SDLK_UP || k == SDLK_w) ? 0 : key_downs[UP];
		key_downs[DOWN] = (k == SDLK_DOWN || k == SDLK_s) ? 0 : key_downs[DOWN];
	}
}

static void		mouse_event(t_e *e, SDL_Event ev)
{
	static _Bool	key_downs[4] = (_Bool[4]){0, 1, 0, 0};
	int				center;
	int				cursor;

	if (e->cursor)
		return ;
	center = e->sdl.w / 2;
	cursor = ev.motion.x;
	if (cursor == center)
		return ;
	rotate(e, (double)(cursor - center) / ((double)e->sdl.w / 95.0), key_downs);
	SDL_WarpMouseInWindow(e->sdl.win, e->sdl.w / 2, e->sdl.h / 2);
	e->update = 1;
}

static _Bool	window_event(t_e *e, SDL_Event ev)
{
	if (ev.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
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
	}
	e->update = 1;
	return (EXIT_SUCCESS);
}

static _Bool	limit_frames(void)
{
	static unsigned int	last_time = 0;
	static unsigned int	current_time;

	current_time = SDL_GetTicks();
	if (current_time < last_time + 10)
		return (1);
	last_time = current_time;
	return (0);
}

_Bool			event_loop(t_e *e)
{
	static _Bool	key_downs[4] = (_Bool[4]){0, 0, 0, 0};
	SDL_Event		ev;

	while (1)
	{
		if (limit_frames())
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
