/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 17:20:09 by mlantonn          #+#    #+#             */
/*   Updated: 2019/06/27 19:07:21 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mysdl.h"

static int	print_sdl_error(t_sdl *sdl, char *str)
{
	if (str)
		ft_dprintf(2, "%s: %s\n", str, SDL_GetError());
	quit_sdl(sdl);
	return (1);
}

void		quit_sdl(t_sdl *sdl)
{
	if (sdl->tex)
		SDL_DestroyTexture(sdl->tex);
	if (sdl->ren)
		SDL_DestroyRenderer(sdl->ren);
	if (sdl->win)
		SDL_DestroyWindow(sdl->win);
	SDL_Quit();
}

int			init_sdl(t_sdl *sdl)
{
	sdl->win = NULL;
	sdl->ren = NULL;
	sdl->tex = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) != 0 )
		return (print_sdl_error(sdl, "Could not init SDL"));
	if (!(sdl->win = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIN_W, WIN_H, SDL_WINDOW_RESIZABLE)))
		return (print_sdl_error(sdl, "Could not create SDL window"));
	if (!(sdl->ren = SDL_CreateRenderer(sdl->win, 0, SDL_RENDERER_ACCELERATED)))
		return (print_sdl_error(sdl, "Could not create SDL renderer"));
	if (!(sdl->tex = SDL_CreateTexture(sdl->ren, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET, WIN_W, WIN_H)))
		return (print_sdl_error(sdl, "Could not create SDL renderer"));
	SDL_SetRenderTarget(sdl->ren, sdl->tex);
	return (0);
}

void		put_pixel(t_sdl *sdl, t_col col, int x, int y)
{
	SDL_SetRenderDrawColor(sdl->ren, col.argb.r, col.argb.g, col.argb.b,
		col.argb.a);
	SDL_RenderDrawPoint(sdl->ren, x, y);
}

void		print_tex(t_sdl *sdl)
{
	SDL_Rect pos;

	pos.x = 0;
	pos.y = 0;
	pos.w = WIN_W;
	pos.h = WIN_H;
	SDL_SetRenderTarget(sdl->ren, NULL);
	SDL_RenderCopy(sdl->ren, sdl->tex, NULL, &pos);
	SDL_RenderPresent(sdl->ren);
	SDL_SetRenderTarget(sdl->ren, sdl->tex);
}
