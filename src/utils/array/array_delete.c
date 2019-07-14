#include "array.h"

inline void	array_delete(t_array *a, void (*delete_content)())
{
	if (a != NULL)
	{
		array_foreach(a, delete_content);
		free(a->p);
		free(a);
	}
}
