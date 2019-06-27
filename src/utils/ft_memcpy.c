#include <stdlib.h>

void	*ft_memcpy(void *d, const void *s, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;
	size_t			idx;

	dest = (unsigned char *)d;
	src = (unsigned char *)s;
	idx = 0;
	while (idx < n)
	{
		dest[idx] = src[idx];
		++idx;
	}
	return (d);
}
