#include <stdlib.h>
#include "array.h"
#include "env.h"

void	env_del(void *a)
{
	if (a != NULL)
		array_delete((t_array *)a, &pair_delete);
}
