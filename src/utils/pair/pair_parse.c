/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:51:38 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:51:38 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pair.h"

inline t_pair	*pair_parse(t_pair *a, const char *s)
{
	if (a != NULL)
	{
		a->key = pair_key_new(s);
		a->value = pair_value_new(s);
		if (a->key == NULL || a->value == NULL)
		{
			free(a->key);
			free(a->value);
			return (NULL);
		}
	}
	return (a);
}
