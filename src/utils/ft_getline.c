#include "wutils.h"

char	**ft_getline(const char **s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (s1[i] != 0)
	{
		if (ft_strncmp(s1[i], s2, len) == 0)
			return ((char **)(s1 + i));
		++i;
	}
	return (NULL);
}
