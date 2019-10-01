/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:50:45 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:50:46 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "singletone.h"
#include "loaded.h"
#include "pair.h"
#include "sg.h"
#include "texture.h"

int		texture_load(void *a, t_pairs *pairs)
{
	static int		(*load[T_TEX_SIZE])(void *, t_pairs *) = {
		[T_TEX_LOADED] = &texture_loaded_load,
		[T_TEX_SG] = &texture_sg_load
	};
	t_texture		***metadata;
	t_texture		*texture;
	unsigned char	*s;

	texture = (t_texture *)a;
	if (texture != NULL && texture->type < T_TEX_SIZE)
	{
		metadata = singletone_texture();
		s = (unsigned char *)pair_get(pairs, "id");
		if (s == NULL || s[0] == '\0' || s[1] != '\0')
			return (-2);
		if (load[texture->type](texture->node, pairs) != 0)
			return (-3);
		(*metadata)[(unsigned int)*s] = texture;
		return (0);
	}
	return (-1);
}
