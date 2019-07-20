#include <stdlib.h>
#include "texture.h"
#include "loaded.h"
#include "sg.h"

void	texture_del(t_texture *a)
{
	static void	(*del[T_TEX_SIZE])(void *) = {
		[T_TEX_LOADED] = &texture_loaded_del,
		[T_TEX_SG] = &texture_sg_del
	};

	if (a != NULL && a->type < T_TEX_SIZE)
	{
		del[a->type](a->node);
		free(a);
	}
}
