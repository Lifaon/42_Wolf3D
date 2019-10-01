/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:49:46 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:49:47 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "map.h"
#include "singletone.h"
#include "wutils.h"

static int	is_valid_map(const char **map,
		const size_t wanted_y,
		const size_t wanted_x)
{
	size_t	x;
	size_t	y;

	if (map == NULL || wanted_x <= 0 || wanted_y <= 0)
		return (0);
	x = 0;
	y = 0;
	while (map[y] != 0 && y < wanted_y)
	{
		if (ft_strlen(map[y]) != wanted_x)
			return (0);
		++y;
	}
	return (y == wanted_y);
}

static char	**copy_map(const char **src, const size_t y)
{
	char	**res;
	size_t	idx;

	res = (char **)malloc(sizeof(char *) * (y + 1));
	if (res == NULL)
		return (NULL);
	idx = 0;
	while (idx < y)
	{
		res[idx] = ft_strdup(src[idx]);
		if (res[idx] == NULL)
		{
			while (--idx != (size_t)-1)
				free(res[idx]);
			return (NULL);
		}
		++idx;
	}
	res[y] = 0;
	return (res);
}

int			map_parse(const char **input)
{
	t_map	*map;
	size_t	x;
	size_t	y;

	y = ft_atoul_base(env_get("MAP_SIZE_Y"), 10);
	x = ft_atoul_base(env_get("MAP_SIZE_X"), 10);
	if (is_valid_map(input, y, x) == 0)
		return (-42);
	map = map_new(0);
	if (map == NULL)
		return (-1);
	if ((map->map = (unsigned char **)copy_map(input, y)) == NULL)
	{
		map_del(map);
		return (-1);
	}
	map->x = x;
	map->y = y;
	(*singletone_map())[0] = map;
	return (0);
}
