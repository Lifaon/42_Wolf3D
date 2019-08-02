#include <stdlib.h>
#include "pair.h"

inline t_pair	*pair_new(void)
{
	t_pair	*res;

	res = (t_pair *)malloc(sizeof(*res));
	if (res != NULL)
	{
		res->key = NULL;
		res->value = NULL;
	}
	return (res);
}
