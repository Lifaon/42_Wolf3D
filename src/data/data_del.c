#include <stdlib.h>
#include "data.h"
#include "block.h"
#include "map.h"

void	data_del(t_data *a)
{
	static void	(*del[T_DA_SIZE])(void *) = {
		[T_DA_MAP] = &map_del,
		[T_DA_BLOCK] = &block_del
	};

	if (a != NULL && a->type < T_DA_SIZE)
	{
		del[a->type](a->node);
		free(a);
	}
}
