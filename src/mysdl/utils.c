/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 17:20:09 by mlantonn          #+#    #+#             */
/*   Updated: 2019/09/25 11:22:18 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mysdl.h"

static int	print_sdl_error(t_sdl *sdl, char *str)
{
	if (str)
		ft_dprintf(2, "%s: %s\n", str, SDL_GetError());
	quit_sdl(sdl);
	return (EXIT_FAILURE);
}

void		quit_sdl(t_sdl *sdl)
{
	if (sdl->tex)
		SDL_DestroyTexture(sdl->tex);
	if (sdl->ren)
		SDL_DestroyRenderer(sdl->ren);
	if (sdl->win)
		SDL_DestroyWindow(sdl->win);
	if (sdl->img)
		free(sdl->img);
	SDL_Quit();
}

int			init_sdl(t_sdl *sdl)
{
	sdl->win = NULL;
	sdl->ren = NULL;
	sdl->tex = NULL;
	sdl->w = WIN_W;
	sdl->h = WIN_H;
	if (!(sdl->img = (t_col *)malloc(sizeof(t_col) * sdl->h * sdl->w)))
	{
		ft_dprintf(2, "Could not allocate needed memory: %s\n",
			strerror(errno));
		return (EXIT_FAILURE);
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		return (print_sdl_error(sdl, "Could not init SDL"));
	if (!(sdl->win = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, sdl->w, sdl->h, SDL_WINDOW_RESIZABLE)))
		return (print_sdl_error(sdl, "Could not create SDL window"));
	if (!(sdl->ren = SDL_CreateRenderer(sdl->win, 0, SDL_RENDERER_ACCELERATED
		| SDL_RENDERER_PRESENTVSYNC)))
		return (print_sdl_error(sdl, "Could not create SDL renderer"));
	if (!(sdl->tex = SDL_CreateTexture(sdl->ren, SDL_PIXELFORMAT_BGRA32,
		SDL_TEXTUREACCESS_TARGET, sdl->w, sdl->h)))
		return (print_sdl_error(sdl, "Could not create SDL renderer"));
	return (EXIT_SUCCESS);
}

void		put_pixel(t_sdl *sdl, t_col col, int x, int y)
{
	sdl->img[x + sdl->w * y] = col;
}

void		print_tex(t_sdl *sdl)
{
	SDL_UpdateTexture(sdl->tex, NULL, sdl->img, sdl->w * 4);
	SDL_RenderCopy(sdl->ren, sdl->tex, NULL, NULL);
	SDL_RenderPresent(sdl->ren);
}
