/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:49:49 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:49:50 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stddef.h>

# define MAP_SPACE 1

typedef struct	s_map
{
	unsigned char	**map;
	size_t			x;
	size_t			y;
}				t_map;

extern void		map_del(void *a);
extern void		*map_new(const size_t ununsed);
extern int		map_parse(const char **input);
extern size_t	map_length(void);

#endif
