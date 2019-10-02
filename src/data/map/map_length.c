/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:49:41 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:49:41 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "singletone.h"

size_t	map_length(void)
{
	t_map	**b;
	size_t	i;
	size_t	c;

	b = *singletone_map();
	i = 0;
	c = 0;
	while (i < MAP_SPACE)
	{
		if (b[i] != NULL)
			++c;
		++i;
	}
	return (c);
}
