/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysdl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 17:24:41 by mlantonn          #+#    #+#             */
/*   Updated: 2019/09/27 13:47:01 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYSDL_H
# define MYSDL_H

# include "SDL.h"
# include "ft_printf.h"
# include <stdint.h>
# include <string.h>
# include <errno.h>

# define WIN_W 1920
# define WIN_H 1080

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

typedef union		u_col24
{
	struct			s_rgb
	{
		uint8_t		b;
		uint8_t		g;
		uint8_t		r;
	}				rgb;
}					t_col24;

typedef struct		s_img
{
	t_col			*arr;
	int				w;
	int				h;
}					t_img;

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

_Bool				load_image(const char *path, t_img *img);

#endif
