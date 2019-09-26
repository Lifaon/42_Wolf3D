#include "env.h"

void	*env_new(void)
{
	return ((void *)array_new(sizeof(t_pair *)));
}
