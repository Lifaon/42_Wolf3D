#include "loaded.h"
#include "pair.h"

#include "ft_printf.h"
int		texture_loaded_load(void *a, t_pairs *pairs)
{
	t_texture_loaded	*load;
	unsigned char		*s;

	load = (t_texture_loaded *)a;
	s = (unsigned char *)pair_get(pairs, "file");
	if (s == NULL)
		return (-3);
	ft_printf("texture file name -> '%s'\n", s);
	return (-1);
}
