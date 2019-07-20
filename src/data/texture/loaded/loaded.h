#ifndef LOADED_H
# define LOADED_H

# include <stddef.h>

/**
 * @param ibuf
 * 32 bits texture, 2d buffer
 *
 * @param cbuf
 * 08 bits texture, 2d buffer
 *
 * @param x
 * 32 bits length on x axis
 *
 * @param y
 * length on y axis
 */

typedef struct	s_texture_loaded
{
	union {
		unsigned int	**ibuf;
		unsigned char	**cbuf;
	};
	size_t			x;
	size_t			y;
}				t_texture_loaded;

void			texture_loaded_del(void *a);
void			*texture_loaded_new(void);

#endif
