/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:49:43 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:49:44 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "map.h"

void	*map_new(const size_t unused)
{
	t_map	*res;

	(void)unused;
	if ((res = (t_map *)malloc(sizeof(*res))) != NULL)
	{
		res->map = NULL;
		res->x = 0;
		res->y = 0;
	}
	return ((void *)res);
}
