#include <stdlib.h>
#include "map.h"

void	*map_new(const size_t unused)
{
	t_map	*res;

	(void)unused;
	if ((res = (t_map *)malloc(sizeof(*res))) != NULL)
	{
		res->map = NULL;
		res->x = 0;
		res->y = 0;
	}
	return ((void *)res);
}
