#include "env.h"
#include "singletone.h"

char	*env_get(const char *key)
{
	return (pair_get((*singletone_env())[0], key));
}
