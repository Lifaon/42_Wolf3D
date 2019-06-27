/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysdl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 17:24:41 by mlantonn          #+#    #+#             */
/*   Updated: 2019/06/27 17:47:15 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYSDL_H
# define MYSDL_H

# include "ft_printf.h"
# include "sdl_structs.h"

# define WIN_W 800
# define WIN_H 800

int		init_sdl(t_sdl *sdl);
void	quit_sdl(t_sdl *sdl);
void	put_pixel(t_sdl *sdl, t_col col, t_pt pt);
void	print_tex(t_sdl *sdl);

#endif
