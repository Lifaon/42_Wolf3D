#include <stdlib.h>
#include "loaded.h"

void	*texture_loaded_new(void)
{
	t_texture_loaded	*res;

	if ((res = (t_texture_loaded *)malloc(sizeof(*res))) != NULL)
	{
		res->ibuf = NULL;
		res->x = 0;
		res->y = 0;
	}
	return ((void *)res);
}
