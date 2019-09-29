#include "block.h"
#include "singletone.h"

t_block	*block_get(const unsigned char id)
{
	t_block	*b;

	b = (*singletone_block())[(unsigned int)id];
	return (b);
}
