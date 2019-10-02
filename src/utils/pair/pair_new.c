/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:51:36 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:51:36 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pair.h"

inline t_pair	*pair_new(void)
{
	t_pair	*res;

	res = (t_pair *)malloc(sizeof(*res));
	if (res != NULL)
	{
		res->key = NULL;
		res->value = NULL;
	}
	return (res);
}
