/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_parse_pairs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 19:35:26 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/02 19:35:28 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "block.h"
#include "texture.h"
#include "singletone.h"
#include "wutils.h"

static int	block_parse_error(t_block ***meta,
		const unsigned int id, const int ret)
{
	(*meta)[id] = NULL;
	return (ret);
}

static int	check_texture_result(t_block ***block_metadata,
		t_texture ***tex_metadata,
		const t_block *b, const unsigned int id)
{
	if ((*tex_metadata)[b->tex_east] == NULL
			|| (*tex_metadata)[b->tex_north] == NULL
			|| (*tex_metadata)[b->tex_south] == NULL
			|| (*tex_metadata)[b->tex_west] == NULL)
		return (block_parse_error(block_metadata, id, -6));
	return (0);
}

static int	block_parse_texture(t_block ***block_metadata,
		t_block *b, void *pairs_p, unsigned int id)
{
	t_texture		***tex_metadata;
	unsigned char	*s;

	tex_metadata = singletone_texture();
	s = (unsigned char *)pair_get((t_pairs *)pairs_p, "north");
	if (s == NULL || s[0] == '\0' || s[1] != '\0')
		return (block_parse_error(block_metadata, id, -5));
	b->tex_north = *s;
	s = (unsigned char *)pair_get((t_pairs *)pairs_p, "south");
	if (s == NULL || s[0] == '\0' || s[1] != '\0')
		return (block_parse_error(block_metadata, id, -5));
	b->tex_south = *s;
	s = (unsigned char *)pair_get((t_pairs *)pairs_p, "east");
	if (s == NULL || s[0] == '\0' || s[1] != '\0')
		return (block_parse_error(block_metadata, id, -5));
	b->tex_east = *s;
	s = (unsigned char *)pair_get((t_pairs *)pairs_p, "west");
	if (s == NULL || s[0] == '\0' || s[1] != '\0')
		return (block_parse_error(block_metadata, id, -5));
	b->tex_west = *s;
	return (check_texture_result(block_metadata, tex_metadata, b, id));
}

int			block_parse_pairs(t_block *b, void *pairs_p)
{
	t_block			***block_metadata;
	unsigned char	*s;
	unsigned int	id;

	block_metadata = singletone_block();
	s = (unsigned char *)pair_get((t_pairs *)pairs_p, "id");
	if (s == NULL || s[0] == '\0' || s[1] != '\0')
		return (-2);
	id = (unsigned int)*s;
	if ((*block_metadata)[id] != NULL)
		block_del((*block_metadata)[id]);
	(*block_metadata)[id] = b;
	s = (unsigned char *)pair_get((t_pairs *)pairs_p, "type");
	if (ft_strlen((const char *)s) != 4)
		return (block_parse_error(block_metadata, id, -2));
	if (ft_strncmp((const char *)s, "void", 4) == 0)
		b->type = T_BL_VOID;
	else if (ft_strncmp((const char *)s, "wall", 4) == 0)
		b->type = T_BL_WALL;
	else
		return (block_parse_error(block_metadata, id, -4));
	if (b->type == T_BL_WALL)
		block_parse_texture(block_metadata, b, pairs_p, id);
	return (0);
}
