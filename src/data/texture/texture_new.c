#include <stdlib.h>
#include "texture.h"
#include "loaded.h"
#include "sg.h"

t_texture	*texture_new(const size_t type)
{
	static void	*(*node_new[T_TEX_SIZE])(void) = {
		[T_TEX_LOADED] = &texture_loaded_new,
		[T_TEX_SG] = &texture_sg_new
	};
	t_texture		*res;

	res = NULL;
	if (type < T_TEX_SIZE && (res = (t_texture *)malloc(sizeof(*res))) != NULL)
	{
		res->type = type;
		if ((res->node = node_new[type]()) == NULL)
		{
			free(res);
			return (NULL);
		}
	}
	return (res);
}
