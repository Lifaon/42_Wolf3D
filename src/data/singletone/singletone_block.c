#include <stdlib.h>
#include "array.h"
#include "block.h"
#include "wutils.h"

t_block	***singletone_block(void)
{
	static t_block **a = NULL;

	if (a == NULL)
	{
		a = malloc(sizeof(t_block *) * 256);
		if (a != NULL)
			ft_memset((void *)a, 0, sizeof(t_block *) * 256);
	}
	return (&a);
}

void	singletone_block_del(void)
{
	t_block	***a;
	size_t	idx;

	a = singletone_block();
	if (*a != NULL)
	{
		idx = 0;
		while (idx < BLOCK_SPACE)
		{
			block_del((*a)[idx]);
			(*a)[idx] = NULL;
			++idx;
		}
		free(*a);
		*a = NULL;
	}
}
