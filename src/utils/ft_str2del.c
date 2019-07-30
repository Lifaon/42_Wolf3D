#include <stdlib.h>

void	ft_str2del(char **s)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != 0)
	{
		free(s[idx]);
		++idx;
	}
	free(s);
}
