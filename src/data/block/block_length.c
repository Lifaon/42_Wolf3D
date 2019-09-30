#include "block.h"
#include "singletone.h"

size_t	block_length(void)
{
	t_block	**b;
	size_t	i;
	size_t	c;

	b = *singletone_block();
	i = 0;
	c = 0;
	while (i < BLOCK_SPACE)
	{
		if (b[i] != NULL)
			++c;
		++i;
	}
	return (c);
}
