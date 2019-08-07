#include <stdlib.h>
#include "array.h"
#include "dicto.h"
#include "ft_printf.h"
#include "data.h"
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

int		has_texture(void *a, void *b)
{
	t_pair	**p;

	(void)b;
	p = (t_pair **)a;
	if (ft_strncmp((*p)->key, "file", 4))
		return (0);
	return (-1);
}

void	*texture_parse(const char **input)
{
	t_dicto_payload	config;
	t_dicto_element	els[3];
	t_pairs			*pairs;
	t_data			*texture;
	size_t			type;

	config_payload(&config, els);
	pairs = dicto(input, (const t_dicto_payload *)&config);
	// if (pairs == NULL)
	// 	ft_dprintf(2, "error on dicto\n");
	type = array_find((t_array *)pairs, &has_texture, NULL)
		? T_TEX_LOADED : T_TEX_SG;
	if ((texture = data_new(T_DA_TEXTURE, type)) != NULL)
	{
		if (texture_load(texture->node, pairs) != 0)
		{
			texture_del((void *)&texture);
			texture = NULL;
		}
	}
	array_delete((t_array *)pairs, &pair_delete);
	return (texture);
}
