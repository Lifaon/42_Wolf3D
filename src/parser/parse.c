/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:45:57 by mlantonn          #+#    #+#             */
/*   Updated: 2019/09/25 11:13:27 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	remove_line_return(t_map *map)
{
	ssize_t	i;
	ssize_t	j;

	i = -1;
	j = 0;
	while (map->str[++i])
	{
		map->str[j] = map->str[i];
		if (map->str[i] != '\n')
			++j;
	}
	map->str[j] = '\0';
}

static int	parse_map(t_map *map)
{
	ssize_t	i;
	ssize_t	tmp;

	i = -1;
	tmp = -1;
	map->x = -1;
	map->y = 0;
	while (map->str[++i])
	{
		++tmp;
		if (map->str[i] == '\n')
		{
			++map->y;
			if (map->x == -1)
				map->x = tmp;
			else if (tmp != map->x)
				return (EXIT_FAILURE);
			tmp = -1;
		}
	}
	if (!i || map->str[i - 1] != '\n')
		return (EXIT_FAILURE);
	remove_line_return(map);
	return (EXIT_SUCCESS);
}

static int	parse_cam(t_map map, t_cam *cam)
{
	ssize_t	i;

	i = -1;
	while (map.str[++i])
		if (map.str[i] == 'P')
			break ;
	if (map.str[i] == '\0')
		return (EXIT_FAILURE);
	cam->pos.x = (double)(i % map.x) + 0.5;
	cam->pos.y = (double)(i / map.x) + 0.5;
	cam->pos_i.x = (int)cam->pos.x;
	cam->pos_i.y = (int)cam->pos.y;
	cam->dir.x = 0;
	cam->dir.y = -1;
	cam->plane.x = -1;
	cam->plane.y = 0;
	return (EXIT_SUCCESS);
}

int			parse(char *path, t_map *map, t_cam *cam)
{
	if ((map->str = read_file(path)) == NULL)
		return (EXIT_FAILURE);
	if (parse_map(map))
	{
		ft_dprintf(2, "wolf3d: Could not parse '%s': Wrong format.\n", path);
		free(map->str);
		return (EXIT_FAILURE);
	}
	if (parse_cam(*map, cam))
	{
		ft_dprintf(2, "wolf3d: Could not run '%s': Player not found.\n", path);
		free(map->str);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
