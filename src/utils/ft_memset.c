#include <stddef.h>

void	ft_memset(void *b, const int c, const size_t len)
{
	size_t			i;
	unsigned char	*m;
	unsigned char	l;

	i = 0;
	m = (unsigned char *)b;
	l = (unsigned char)c;
	while (i < len)
	{
		m[i] = l;
		++i;
	}
}
