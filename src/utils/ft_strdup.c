#include <stdlib.h>
#include "wutils.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	len;

	len = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res != NULL)
	{
		ft_memcpy(res, s, len);
		res[len] = 0;
	}
	return (res);
}
