#ifndef LOADED_H
# define LOADED_H

# include <stddef.h>
# include "pair.h"

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

struct s_col24
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
};


typedef struct	s_texture_loaded
{
	union {
		unsigned int	*ibuf;
		unsigned char	*cbuf;
	};
	size_t			x;
	size_t			y;
}				t_texture_loaded;

extern void			texture_loaded_del(void *a);
extern int			texture_loaded_load(void *a, t_pairs *pairs);
extern void			*texture_loaded_new(void);
extern unsigned int	texture_loaded_get_color(const void *t,
		const double y, const double x);

#endif
