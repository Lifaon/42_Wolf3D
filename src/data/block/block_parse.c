/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:49:06 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:49:07 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "array.h"
#include "block.h"
#include "dicto.h"
#include "singletone.h"
#include "wutils.h"
#include "ft_printf.h"

static void	config_payload2(t_dicto_element *els)
{
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
}

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
	config_payload2(els);
	conf->els = els;
}

int			block_parse(const char **input)
{
	t_dicto_payload	config;
	t_dicto_element	els[6];
	t_pairs			*pairs;
	t_block			*block;
	int				ret;

	config_payload(&config, els);
	pairs = dicto(input, (const t_dicto_payload *)&config);
	if (pairs == NULL)
	{
		ft_dprintf(2, "error on dicto\n");
		return (-1);
	}
	ret = -1;
	if ((block = (t_block *)block_new()) != NULL)
	{
		if ((ret = block_parse_pairs(block, pairs)) != 0)
		{
			block_del(block);
			block = NULL;
		}
	}
	array_delete((t_array *)pairs, &pair_delete);
	return (ret);
}
