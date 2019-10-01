/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:51:32 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:51:32 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include "pair.h"
#include "wutils.h"

static int	same_key(void *a, void *b)
{
	t_pair	**p;

	p = (t_pair **)a;
	if (ft_strncmp((const char *)(*p)->key, (const char *)b,
			ft_strlen((const char *)b)) == 0)
		return (0);
	return (-1);
}

char	*pair_get(t_pairs *p, const char *key)
{
	t_pair	**pair;

	pair = (t_pair **)array_find((t_array *)p, &same_key, (void *)key);
	if (pair == NULL || *pair == NULL)
		return (NULL);
	return ((*pair)->value);
}
