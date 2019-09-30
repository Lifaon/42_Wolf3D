#include "env.h"
#include "singletone.h"

size_t	env_length(void)
{
	t_env	**b;
	size_t	i;
	size_t	c;

	b = *singletone_env();
	i = 0;
	c = 0;
	while (i < ENV_SPACE)
	{
		if (b[i] != NULL)
			++c;
		++i;
	}
	return (c);
}
