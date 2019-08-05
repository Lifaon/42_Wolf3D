#include <stdlib.h>
#include "pair.h"

inline void	pair_delete(t_pair **a)
{
	if (a != NULL && *a != NULL)
	{
		free((*a)->key);
		free((*a)->value);
		free((*a));
	}
}
