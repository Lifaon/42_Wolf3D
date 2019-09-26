/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:02:06 by mlantonn          #+#    #+#             */
/*   Updated: 2019/09/26 17:06:14 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static _Bool	quit_all(t_e e, _Bool ret)
{
	free(e.map.str);
	quit_sdl(&e.sdl);
	return (ret);
}

static _Bool	display(t_e e)
{
	_Bool ret;

	if (init_sdl(&e.sdl))
		return (EXIT_FAILURE);
	e.show_cursor = !SDL_ShowCursor(SDL_DISABLE);
	SDL_WarpMouseInWindow(e.sdl.win, e.sdl.w / 2, e.sdl.h / 2);
	if (raycasting(&e))
		return (quit_all(e, EXIT_FAILURE));
	ret = event_loop(&e);
	return (quit_all(e, ret));
}

int				main(int ac, char **av)
{
	t_e	e;

	if (ac != 2)
	{
		ft_dprintf(2, "Usage: ./wolf3d <some-map.wolf>\n");
		return (EXIT_FAILURE);
	}
	if (parse(av[1], &e.map, &e.cam))
		return (EXIT_FAILURE);
	return (display(e));
}
