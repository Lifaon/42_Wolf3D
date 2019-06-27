#include "array.h"

inline void	array_delete(t_array *a, void delete_content(void *, size_t))
{
	if (delete_content != NULL)
		delete_content(a->p, a->length);
	free(a->p);
	free(a);
}
