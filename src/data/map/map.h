#ifndef MAP_H
# define MAP_H

#include <stddef.h>

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

void			map_del(void *a);
void			*map_new(void);

#endif
