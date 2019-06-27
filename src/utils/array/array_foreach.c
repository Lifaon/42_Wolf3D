#include "array.h"

void	array_foreach(t_array *a, void (*callback)())
{
	void	*pos;
	size_t	p_size;
	size_t	idx;
	size_t	max;

	if (callback != NULL)
	{
		pos = a->p;
		p_size = a->p_size;
		max = a->length;
		idx = 0;
		while (idx < max)
		{
			callback(pos, idx, a);
			pos += p_size;
			++idx;
		}
	}
}
