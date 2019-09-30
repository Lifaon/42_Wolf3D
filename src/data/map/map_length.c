#include "map.h"
#include "singletone.h"

size_t	map_length(void)
{
	t_map	**b;
	size_t	i;
	size_t	c;

	b = *singletone_map();
	i = 0;
	c = 0;
	while (i < MAP_SPACE)
	{
		if (b[i] != NULL)
			++c;
		++i;
	}
	return (c);
}
