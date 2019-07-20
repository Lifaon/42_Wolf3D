#include <stdlib.h>
#include "loaded.h"

void	texture_loaded_del(void *a)
{
	t_texture_loaded	*b;
	size_t				idx;

	b = (t_texture_loaded *)a;
	if (b != NULL)
	{
		idx = 0;
		while (idx < b->y)
		{
			free(b->cbuf[idx]);
			++idx;
		}
		free(b->cbuf);
		free(b);
	}
}
