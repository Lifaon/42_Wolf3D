#include "sg.h"
#include "pair.h"
#include "wutils.h"

int		texture_sg_load(void *a, t_pairs *pairs)
{
	t_texture_sg	*sg;
	char			*pair_value;

	sg = (t_texture_sg *)a;
	pair_value = pair_get(pairs, "color");
	if (pair_value == NULL || pair_value[0] != '#')
		return (-1);
	sg->color = ft_atoul_base(pair_value + 1, 16);
	return (0);
}
