#include "loaded.h"
#include "mysdl.h"
#include "sg.h"
#include "texture.h"

t_col	texture_get_color(const t_texture *t, const double y, const double x)
{
	static unsigned int	(*get[T_TEX_SIZE])(const void *,
			const double, const double) = {
		[T_TEX_LOADED] = &texture_loaded_get_color,
		[T_TEX_SG] = &texture_sg_get_color
	};
	t_col				res;

	if (t != NULL && t->type < T_TEX_SIZE)
	{
		res.c = get[t->type](t->node, y, x);
	}
	else
		res.c = 0;
	return (res);
}
