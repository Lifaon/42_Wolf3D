#include <stdlib.h>
#include "block.h"

void	block_del(void *a)
{
	t_block	*b;

	b = (t_block *)a;
	if (b != NULL)
	{
		free(b);
	}
}
