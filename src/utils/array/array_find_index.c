#include "array.h"

size_t	array_find_index(t_array *a, int (*cmp)(void *, void *), void *to_find)
{
	void	*pos;
	size_t	max;
	size_t	idx;
	size_t	p_size;

	if (cmp == NULL)
		return ((size_t)-1);
	pos = a->p;
	max = a->length;
	idx = 0;
	p_size = a->p_size;
	while (idx < max)
	{
		if (cmp(pos, to_find) == 0)
			return (idx);
		++idx;
		pos += p_size;
	}
	return ((size_t)-1);
}
