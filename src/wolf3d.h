/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:02:55 by mlantonn          #+#    #+#             */
/*   Updated: 2019/06/27 18:29:18 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "data.h"
# include "mysdl.h"
# include "SDL.h"

typedef struct	s_datas
{
	t_data	*p;
	size_t	length;
	size_t	capacity;
	size_t	p_size;
}				t_datas;

#endif
