/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dicto.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:48:40 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:48:41 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include "dicto.h"
#include "pair.h"
#include "wutils.h"

t_dicto_element	*dicto_get_elem(const char *key, const t_dicto_payload *conf)
{
	t_dicto_element	*els;
	size_t			max;
	size_t			idx;
	size_t			length;

	idx = 0;
	max = conf->length;
	length = ft_strlen(key);
	els = conf->els;
	while (idx < max)
	{
		if (length == els[idx].length
				&& ft_memcmp(key, els[idx].key, length) == 0)
			return (els + idx);
		++idx;
	}
	return (NULL);
}

static int	dicto_parse(t_pairs *a,
		const char **input, const t_dicto_payload *conf)
{
	t_dicto_element	*target;
	t_pair			*pair;
	size_t			idx;
	size_t			max;

	max = conf->length;
	idx = 0;
	while (input[idx] != 0)
	{
		pair = pair_new();
		if (pair == NULL || pair_parse(pair, input[idx]) == NULL
				|| (target = dicto_get_elem(pair->key, conf)) == NULL
				|| ft_strlen(pair->value) > target->max_length
				|| (target->is_valid != NULL && !target->is_valid())
				|| array_push((t_array *)a, (const void *)&pair, 1) == EXIT_FAILURE)
		{
			pair_delete(&pair);
			return (-1);
		}
		++idx;
	}
	return (0);
}

t_pairs		*dicto(const char **input, const t_dicto_payload *conf)
{
	t_pairs	*res;

	res = (t_pairs *)array_new(sizeof(t_pair *));
	if (res != NULL)
	{
		if (dicto_parse(res, input, conf) != 0)
		{
			array_delete((t_array *)res, &pair_delete);
			return (NULL);
		}
	}
	return (res);
}
