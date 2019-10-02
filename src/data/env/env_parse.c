/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:49:26 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:49:27 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include "dicto.h"
#include "pair.h"
#include "env.h"
#include "singletone.h"
#include "ft_printf.h"

static void	config_payload2(t_dicto_element *els)
{
	els[2] = (t_dicto_element){
		.key = "SPAWN_X",
		.length = 7,
		.max_length = 4,
		.is_valid = NULL
	};
	els[3] = (t_dicto_element){
		.key = "SPAWN_Y",
		.length = 7,
		.max_length = 4,
		.is_valid = NULL
	};
}

static void	config_payload(t_dicto_payload *conf, t_dicto_element *els)
{
	conf->length = 4;
	els[0] = (t_dicto_element){
		.key = "MAP_SIZE_X",
		.length = 10,
		.max_length = 4,
		.is_valid = NULL
	};
	els[1] = (t_dicto_element){
		.key = "MAP_SIZE_Y",
		.length = 10,
		.max_length = 4,
		.is_valid = NULL
	};
	config_payload2(els);
	conf->els = els;
}

int			env_parse(const char **input)
{
	t_dicto_payload	config;
	t_dicto_element	els[4];
	t_pairs			*pairs;

	config_payload(&config, els);
	pairs = dicto(input, (const t_dicto_payload *)&config);
	if (pairs == NULL)
	{
		ft_dprintf(2, "error on dicto\n");
		return (-1);
	}
	(*singletone_env())[0] = pairs;
	return (0);
}
