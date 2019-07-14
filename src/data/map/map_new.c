#include <stdlib.h>
#include "map.h"

void	*map_new(void)
{
	t_map	*res;

	if ((res = (t_map *)malloc(sizeof(*res))) != NULL)
	{
		res->map = NULL;
		res->x = 0;
		res->y = 0;
	}
	return ((void *)res);
}
