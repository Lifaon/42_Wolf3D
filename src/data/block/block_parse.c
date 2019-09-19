#include <stdlib.h>
#include "array.h"
#include "dicto.h"
#include "data.h"
#include "block.h"
#include "singletone.h"

#include "wutils.h"
#include "ft_printf.h"
static void	config_payload(t_dicto_payload *conf, t_dicto_element *els)
{
	conf->length = 6;
	els[0] = (t_dicto_element){
		.key = "id",
		.length = 2,
		.max_length = 1,
		.is_valid = NULL
	};
	els[1] = (t_dicto_element){
		.key = "type",
		.length = 4,
		.max_length = 4,
		.is_valid = NULL
	};
	els[2] = (t_dicto_element){
		.key = "north",
		.length = 5,
		.max_length = 1,
		.is_valid = NULL
	};
	els[3] = (t_dicto_element){
		.key = "south",
		.length = 5,
		.max_length = 1,
		.is_valid = NULL
	};
	els[4] = (t_dicto_element){
		.key = "east",
		.length = 4,
		.max_length = 1,
		.is_valid = NULL
	};
	els[5] = (t_dicto_element){
		.key = "west",
		.length = 4,
		.max_length = 1,
		.is_valid = NULL
	};
	conf->els = els;
}

void		show_pair(void *e)
{
	t_pair	**p;

	p = (t_pair **)e;
	if (p != NULL && *p != NULL)
		ft_printf("[%s] => '%s'\n", (*p)->key, (*p)->value);
	else
		ft_printf("pair === NULL\n");
}

int			block_parse_pairs(void *e, void *pairs_p)
{
	return 0;
	// t_block			**metadata;
	t_block			*b;
	unsigned char	*s;
	unsigned int	id;

	// metadata = singletone_block();
	// if (metadata == NULL)
		// return (-1);
	b = (t_block *)e;
	s = (unsigned char *)pair_get((t_pairs *)pairs_p, "id");
	if (s == NULL || s[0] == '\0' || s[1] != '\0')
		return (-2);
	id = (unsigned int)*s;
	// if (metadata[id] == NULL
		// && (metadata[id] = (t_block *)malloc(sizeof(t_block))) == NULL)
		// return (-1);
	s = (unsigned char *)pair_get((t_pairs *)pairs_p, "type");
	if (ft_strlen((const char *)s) != 4)
		return (-3);
	if (ft_strncmp((const char *)s, "void", 4) == 0)
		b->type = T_BL_VOID;
	else if (ft_strncmp((const char *)s, "wall", 4) == 0)
		b->type = T_BL_WALL;

	// TODO change this by parse xpm files and ptr to t_texture
	s = (unsigned char *)pair_get((t_pairs *)pairs_p, "north");
	b->tex_north = s;
	s = (unsigned char *)pair_get((t_pairs *)pairs_p, "south");
	b->tex_south = s;
	s = (unsigned char *)pair_get((t_pairs *)pairs_p, "east");
	b->tex_east = s;
	s = (unsigned char *)pair_get((t_pairs *)pairs_p, "west");
	b->tex_west = s;
	// b->type = metadata[id]->type;
	// b->tex_north = metadata[id]->tex_north;
	// b->tex_south = metadata[id]->tex_south;
	// b->tex_east = metadata[id]->tex_east;
	// b->tex_west = metadata[id]->tex_west;
	return (0);
}

void		*block_parse(const char **input)
{
	t_dicto_payload	config;
	t_dicto_element	els[3];
	t_pairs			*pairs;
	t_data			*block;

	block = NULL;
	config_payload(&config, els);
	pairs = dicto(input, (const t_dicto_payload *)&config);
	if (pairs == NULL)
		ft_dprintf(2, "error on dicto\n");
	array_foreach((t_array *)pairs, &show_pair); //
	ft_printf("hello world !\n");
	// change into block_new
	if ((block = data_new(T_DA_BLOCK, 0)) != NULL)
	{
		ft_printf("block parse pairs !\n");
		if (block_parse_pairs(block->node, pairs) != 0)
		{
			ft_printf("block del !\n");
			block_del((void *)&block);
			block = NULL;
		}
		else
		{
			// push block into singletone id
		}
	}
	ft_printf("hello world mid !\n");
	array_delete((t_array *)pairs, &pair_delete);
	ft_printf("hello world end !\n");
	ft_printf("return addr => %#x\n", block);
	return ((void *)block);
}
