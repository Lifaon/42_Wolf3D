/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 17:45:30 by mlantonn          #+#    #+#             */
/*   Updated: 2019/06/27 19:06:34 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_STRUCTS_H
# define SDL_STRUCTS_H

# include <stdint.h>
# include "SDL.h"

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Texture		*tex;
}					t_sdl;

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

#endif
