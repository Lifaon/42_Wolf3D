#include "array.h"
#include "wutils.h"

int		array_push_at(t_array *a, void const *src, size_t n_element,
	size_t const at)
{
	void	*pos;
	size_t	used_space;
	size_t	size_to_push;

	if (src == NULL)
		return (EXIT_FAILURE);
	size_to_push = n_element * a->p_size;
	used_space = a->length * a->p_size;
	if (a->capacity - used_space < size_to_push)
	{
		if (array_realloc(a, a->length + n_element, a->p_size) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	pos = a->p + at * a->p_size;
	if (at < a->length)
		ft_memmove(pos + size_to_push, pos,
				a->length * a->p_size - size_to_push);
	ft_memcpy(pos, src, size_to_push);
	a->length += n_element;
	return (EXIT_SUCCESS);
}
