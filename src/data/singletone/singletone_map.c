#include <stdlib.h>
#include "map.h"
#include "wutils.h"

t_map	***singletone_map(void)
{
	static t_map **a = NULL;

	if (a == NULL)
	{
		a = (t_map **)malloc(sizeof(t_map *) * MAP_SPACE);
		if (a != NULL)
		{
			ft_memset((void *)a, 0, sizeof(t_map *) * MAP_SPACE);
		}
	}
	return (&a);
}

void	singletone_map_del(void)
{
	t_map	***a;
	size_t	idx;

	a = singletone_map();
	if (*a != NULL)
	{
		idx = 0;
		while (idx < MAP_SPACE)
		{
			map_del((*a)[idx]);
			(*a)[idx] = NULL;
			++idx;
		}
		free(*a);
		*a = NULL;
	}
}
