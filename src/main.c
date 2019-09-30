/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:02:06 by mlantonn          #+#    #+#             */
/*   Updated: 2019/09/30 17:13:14 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "singletone.h"
#include "wutils.h"

static _Bool	quit_all(t_e e, _Bool ret)
{
	if (e.sky.arr)
		free(e.sky.arr);
	quit_sdl(&e.sdl);
	return (ret);
}

static _Bool	display(t_e e)
{
	_Bool ret;

	if (init_sdl(&e.sdl))
		return (EXIT_FAILURE);
	if (load_image("textures/vaporwave.bmp", &e.sky))
		return (quit_all(e, EXIT_FAILURE));
	e.show_cursor = !SDL_ShowCursor(SDL_DISABLE);
	e.outlines = 1;
	e.skybox = 1;
	e.fps = 60;
	SDL_WarpMouseInWindow(e.sdl.win, e.sdl.w / 2, e.sdl.h / 2);
	if (raycasting(&e))
		return (quit_all(e, EXIT_FAILURE));
	ret = event_loop(&e);
	return (quit_all(e, ret));
}

__attribute__((constructor))
static
void	on_enter(void)
{
	ft_printf("enter constructor\n");
	if (*singletone_block() == NULL
			|| *singletone_texture() == NULL
			|| *singletone_map() == NULL
			|| *singletone_env() == NULL)
	{
		ft_dprintf(2, "error: not enought memory to launch program\n");
		exit(EXIT_FAILURE);
	}
}

__attribute__((destructor))
static
void	on_exit(void)
{
	ft_printf("enter destructor\n");
	singletone_block_del();
	singletone_env_del();
	singletone_map_del();
	singletone_texture_del();
}

int				main(int ac, char **av)
{
	t_e	e;

	if (ac != 2)
	{
		ft_dprintf(2, "Usage: ./wolf3d <some-map.wolf>\n");
		return (EXIT_FAILURE);
	}
	if (parse_wolf_map(av[1]) != 0)
		return (EXIT_FAILURE);
	e.map = (*singletone_map())[0];
	e.cam.pos.y = (double)(ft_atoul_base(env_get("SPAWN_Y"), 10)) + 0.5;
	e.cam.pos.x = (double)(ft_atoul_base(env_get("SPAWN_X"), 10)) + 0.5;
	e.cam.pos_i.x = (int)e.cam.pos.x;
	e.cam.pos_i.y = (int)e.cam.pos.y;
	e.cam.dir.x = 0;
	e.cam.dir.y = -1;
	e.cam.plane.x = -1;
	e.cam.plane.y = 0;
	return (display(e));
}
