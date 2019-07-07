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

# include "mysdl.h"
# include "SDL.h"

enum e_data_type
{
	T_DA_NONE = -1,
	T_DA_MAP,
	T_DA_BLOCK,
	T_DA_SIZE
};

enum e_block_type
{
	T_BL_NONE = -1,
	T_BL_VOID,
	T_BL_WALL,
	T_BL_SIZE
};

/**
 * @param map
 * 2d map with 8 bits range for block id
 * REMINDER not a string
 *
 * @param x
 * map length on x axis
 *
 * @param y
 * map length on y axis
 */

typedef struct	s_map
{
	unsigned char	**map;
	size_t			x;
	size_t			y;
}				t_map;

/**
 * @param type
 * enum e_block_type values
 *
 * @param tex_north
 * north's texture side
 *
 * @param tex_south
 * south's texture side
 *
 * @param tex_east
 * east's texture side
 *
 * @param tex_west
 * west's texture side
 */

typedef struct	s_block
{
	size_t			type;
	unsigned char	*tex_north;
	unsigned char	*tex_south;
	unsigned char	*tex_east;
	unsigned char	*tex_west;
}				t_block;

/**
 * @param type
 * enum e_data_type values
 *
 * @param node
 * ptr to the struct of @param type
 */

typedef struct	s_data
{
	size_t	type;
	void	*node;
}				t_data;

#endif
