#include <stdlib.h>

_Bool	is_pow_of2(size_t const n)
{
	return ((((n) - 1) & (n)) == 0);
}
