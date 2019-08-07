#include "loaded.h"
#include "pair.h"
#include "sg.h"
#include "texture.h"

int		texture_load(void *a, t_pairs *pairs)
{
	static int	(*load[T_TEX_SIZE])(void *, t_pairs *) = {
		[T_TEX_LOADED] = &texture_loaded_load,
		[T_TEX_SG] = &texture_sg_load
	};
	t_texture	*texture;

	texture = (t_texture *)a;
	if (texture != NULL && texture->type < T_TEX_SIZE)
		return (load[texture->type](texture->node, pairs));
	return (-1);
}
