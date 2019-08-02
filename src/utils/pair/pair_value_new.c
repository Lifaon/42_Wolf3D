#include "wutils.h"

char	*pair_value_new(const char *s)
{
	char	*ptr;

	ptr = ft_strchr(s, '=');
	if (ptr != NULL)
		return (ft_strdup(ptr + 1));
	return (NULL);
}
