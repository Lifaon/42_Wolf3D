#include <stdlib.h>
#include "block.h"

void	*block_new(void)
{
	t_block	*res;

	if ((res = (t_block *)malloc(sizeof(*res))) != NULL)
	{
		res->type = T_BL_NONE;
		res->tex_north = 0;
		res->tex_south = 0;
		res->tex_east = 0;
		res->tex_west = 0;
	}
	return ((void *)res);
}
