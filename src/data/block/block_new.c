#include <stdlib.h>
#include "block.h"

void	*block_new(const size_t unused)
{
	t_block	*res;

	(void)unused;
	if ((res = (t_block *)malloc(sizeof(*res))) != NULL)
	{
		res->type = T_BL_NONE;
		res->tex_north = NULL;
		res->tex_south = NULL;
		res->tex_east = NULL;
		res->tex_west = NULL;
	}
	return ((void *)res);
}
