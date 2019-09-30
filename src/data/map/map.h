#ifndef MAP_H
# define MAP_H

# include <stddef.h>

# define MAP_SPACE 1

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

extern void		map_del(void *a);
extern void		*map_new(const size_t ununsed);
extern int		map_parse(const char **input);
extern size_t	map_length(void);

#endif
