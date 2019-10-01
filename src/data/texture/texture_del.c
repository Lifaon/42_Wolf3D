/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:50:37 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:50:37 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "texture.h"
#include "loaded.h"
#include "sg.h"

void	texture_del(void *a)
{
	static void	(*del[T_TEX_SIZE])(void *) = {
		[T_TEX_LOADED] = &texture_loaded_del,
		[T_TEX_SG] = &texture_sg_del
	};
	t_texture	*t;

	t = (t_texture *)a;
	if (t != NULL && t->type < T_TEX_SIZE)
	{
		del[t->type](t->node);
		free(a);
	}
}
