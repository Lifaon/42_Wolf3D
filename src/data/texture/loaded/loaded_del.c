#include <stdlib.h>
#include "loaded.h"

void	texture_loaded_del(void *a)
{
	t_texture_loaded	*b;

	b = (t_texture_loaded *)a;
	if (b != NULL)
	{
		free(b->cbuf);
		free(b);
	}
}
