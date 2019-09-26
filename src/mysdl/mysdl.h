/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysdl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 17:24:41 by mlantonn          #+#    #+#             */
/*   Updated: 2019/09/26 17:51:30 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYSDL_H
# define MYSDL_H

# include "SDL.h"
# include "ft_printf.h"
# include <stdint.h>
# include <string.h>
# include <errno.h>

# define WIN_W 1280
# define WIN_H 720

typedef union		u_col
{
	uint32_t		c;
	struct			s_argb
	{
		uint8_t		b;
		uint8_t		g;
		uint8_t		r;
		uint8_t		a;
	}				argb;
}					t_col;

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Texture		*tex;
	t_col			*img;
	int				w;
	int				h;
}					t_sdl;

int					init_sdl(t_sdl *sdl);
void				quit_sdl(t_sdl *sdl);
void				put_pixel(t_sdl *sdl, t_col col, int x, int y);
void				print_tex(t_sdl *sdl);

#endif
