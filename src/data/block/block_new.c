/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:49:04 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:49:05 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "block.h"

void	*block_new(void)
{
	t_block	*res;

	if ((res = (t_block *)malloc(sizeof(*res))) != NULL)
	{
		res->type = T_BL_NONE;
		res->tex_north = 0;
		res->tex_south = 0;
		res->tex_east = 0;
		res->tex_west = 0;
	}
	return ((void *)res);
}
