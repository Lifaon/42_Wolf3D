#ifndef TEXTURE_H
# define TEXTURE_H

# include <stddef.h>
# include "pair.h"
# include "type.h"
# include "mysdl.h"
# define TEXTURE_SPACE 256

enum e_texture_type
{
	T_TEX_NONE = -1,
	T_TEX_LOADED,
	T_TEX_SG,
	T_TEX_SIZE
};

typedef t_type	t_texture;

extern void			texture_del(void *a);
extern int			texture_load(void *a, t_pairs *pairs);
extern void			*texture_new(const size_t type);
extern int			texture_parse(const char **input);
extern t_col		texture_get_color(const t_texture *t,
		const double y, const double x);

#endif
