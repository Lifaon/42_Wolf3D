#include <stdlib.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	size_t			i;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	while (*(ss1 + i) != *(ss2 + i) && i < n)
		++i;
	return ((i == n) ? 0 : *(ss1 + i) - *(ss2 + i));
}
