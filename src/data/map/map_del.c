#include <stdlib.h>
#include "map.h"

void	map_del(void *a)
{
	t_map	*b;
	size_t	y;

	b = (t_map *)a;
	if (b != NULL)
	{
		y = 0;
		while (y < b->y)
		{
			free(b->map[y]);
			++y;
		}
		free(b->map);
		free(b);
	}
}
