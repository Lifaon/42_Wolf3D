#include "array.h"

inline void	array_delete(t_array *a, void delete_content(void *, size_t))
{
	if (a != NULL)
	{
		if (delete_content != NULL)
			delete_content(a->p, a->length);
		// array_foreach(a, delete_content);
		free(a->p);
		free(a);
	}
}
