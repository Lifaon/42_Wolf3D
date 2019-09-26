#include <stdlib.h>
#include "array.h"
#include "dicto.h"
#include "ft_printf.h"
#include "texture.h"
#include "wutils.h"

static void	config_payload(t_dicto_payload *conf, t_dicto_element *els)
{
	conf->length = 3;
	els[0] = (t_dicto_element){
		.key = "id",
		.length = 2,
		.max_length = 1,
		.is_valid = NULL
	};
	els[1] = (t_dicto_element){
		.key = "file",
		.length = 4,
		.max_length = 256,
		.is_valid = NULL
	};
	els[2] = (t_dicto_element){
		.key = "color",
		.length = 5,
		.max_length = 9,
		.is_valid = NULL
	};
	conf->els = els;
}

static int	has_texture(void *a, void *b)
{
	t_pair	**p;

	(void)b;
	p = (t_pair **)a;
	if (ft_strncmp((*p)->key, "file", 4) == 0)
		return (0);
	return (-1);
}

int			texture_parse(const char **input)
{
	t_dicto_payload	config;
	t_dicto_element	els[3];
	t_pairs			*pairs;
	t_texture		*texture;
	size_t			type;
	int				ret;

	config_payload(&config, els);
	pairs = dicto(input, (const t_dicto_payload *)&config);
	if (pairs == NULL)
	{
		ft_dprintf(2, "error on dicto\n");
		array_delete((t_array *)pairs, &pair_delete);
		return (-1);
	}
	type = array_find((t_array *)pairs, &has_texture, NULL)
		? T_TEX_LOADED : T_TEX_SG;
	ret = -1;
	if ((texture = texture_new(type)) != NULL)
	{
		if ((ret = texture_load(texture, pairs)) != 0)
		{
			texture_del(texture);
			texture = NULL;
		}
	}
	array_delete((t_array *)pairs, &pair_delete);
	return (ret);
}
