#include <stdio.h>
#include "wutils.h"

inline static int	is_lowercase(const char c)
{
	return (c >= 'a' && c <= 'z');
}

unsigned long long	ft_atoul_base(const char *s, int base)
{
	unsigned long long	val;
	char				*conv[2];
	int					is_lower;

	if (base < 2 || base > 16)
		return (0);
	conv[0] = (char *)"0123456789ABCDEF";
	conv[1] = (char *)"0123456789abcdef";
	val = 0;
	while ((*s >= '0' && *s <= '9')
			|| (*s >= 'a' && *s <= 'z')
			|| (*s >= 'A' && *s <= 'Z'))
	{
		is_lower = is_lowercase(*s);
		val = (val * base)
			+ (ft_strchr((const char *)(conv[is_lower]), (const int)*s)
				- (const char *)(conv[is_lower]));
		++s;
	}
	return (val);
}
