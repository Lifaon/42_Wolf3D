#include "array.h"

inline int	array_push(t_array *a, void const *src, size_t n_element)
{
	return (array_push_at(a, src, n_element, a->length));
}
