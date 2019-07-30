#ifndef TEXTURE_H
# define TEXTURE_H

# include <stddef.h>
# include "type.h"

enum e_texture_type
{
	T_TEX_NONE = -1,
	T_TEX_LOADED,
	T_TEX_SG,
	T_TEX_SIZE
};

typedef t_type	t_texture;

void				texture_del(t_texture *a);
t_texture			*texture_new(const size_t type);
void				*texture_parse(const char **input);

#endif
