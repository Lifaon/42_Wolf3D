#include <stdlib.h>
#include "texture.h"
#include "loaded.h"
#include "sg.h"

void	texture_del(void *a)
{
	static void	(*del[T_TEX_SIZE])(void *) = {
		[T_TEX_LOADED] = &texture_loaded_del,
		[T_TEX_SG] = &texture_sg_del
	};
	t_texture	*t;

	t = (t_texture *)a;
	if (t != NULL && t->type < T_TEX_SIZE)
	{
		del[t->type](t->node);
		free(a);
	}
}
