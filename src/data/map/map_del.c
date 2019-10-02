/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:49:38 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:49:39 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "map.h"

void	map_del(void *a)
{
	t_map	*b;
	size_t	y;

	b = (t_map *)a;
	if (b != NULL)
	{
		y = 0;
		while (y < b->y)
		{
			free(b->map[y]);
			++y;
		}
		free(b->map);
		free(b);
	}
}
