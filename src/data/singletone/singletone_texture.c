/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singletone_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:50:03 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:50:03 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "array.h"
#include "texture.h"
#include "wutils.h"

t_texture	***singletone_texture(void)
{
	static t_texture	**a = NULL;

	if (a == NULL)
	{
		a = (t_texture **)malloc(sizeof(t_texture *) * TEXTURE_SPACE);
		if (a != NULL)
			ft_memset((void *)a, 0, sizeof(t_texture *) * TEXTURE_SPACE);
	}
	return (&a);
}

void		singletone_texture_del(void)
{
	t_texture	***a;
	size_t		idx;

	a = singletone_texture();
	if (*a != NULL)
	{
		idx = 0;
		while (idx < TEXTURE_SPACE)
		{
			texture_del((*a)[idx]);
			++idx;
		}
		free(*a);
		*a = NULL;
	}
}
