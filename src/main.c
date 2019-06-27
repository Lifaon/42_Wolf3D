/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:02:06 by mlantonn          #+#    #+#             */
/*   Updated: 2019/06/27 19:19:03 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"
#include "wolf3d.h"

int		main(int argc, char **argv)
{
	t_sdl		sdl;
	SDL_Event	ev;
	t_col		col;

	if (init_sdl(&sdl))
		return (1);
	print_tex(&sdl);
	while (SDL_WaitEvent(&ev))
	{
		if (ev.window.event == SDL_WINDOWEVENT_CLOSE ||
			ev.key.keysym.sym == SDLK_ESCAPE)
			break;
	}
	quit_sdl(&sdl);
	return (0);
}
