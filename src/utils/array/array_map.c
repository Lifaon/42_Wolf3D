#include "array.h"

t_array	*array_map(t_array *a, void *(*callback)(), void (*del)(void *, size_t))
{
	t_array	*mapped;
	void	*pos;
	void	*ret;
	size_t	idx;
	size_t	max;

	mapped = NULL;
	if (callback == NULL || (mapped = array_new(a->p_size)) == NULL
			|| array_realloc(mapped, a->length, a->p_size) == EXIT_FAILURE)
	{
		array_delete(mapped, NULL);
		return (NULL);
	}
	pos = a->p;
	max = a->length;
	idx = 0;
	while (idx < max)
	{
		if ((ret = callback(pos, idx, a)) == NULL
				|| array_push(mapped, &ret, 1) == EXIT_FAILURE)
		{
			array_delete(mapped, del);
			return (NULL);
		}
		pos += a->p_size;
		++idx;
	}
	return (mapped);
}
