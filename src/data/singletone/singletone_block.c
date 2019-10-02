/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singletone_block.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:49:53 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:49:53 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "array.h"
#include "block.h"
#include "wutils.h"

t_block	***singletone_block(void)
{
	static t_block **a = NULL;

	if (a == NULL)
	{
		a = (t_block **)malloc(sizeof(t_block *) * BLOCK_SPACE);
		if (a != NULL)
			ft_memset((void *)a, 0, sizeof(t_block *) * BLOCK_SPACE);
	}
	return (&a);
}

void	singletone_block_del(void)
{
	t_block	***a;
	size_t	idx;

	a = singletone_block();
	if (*a != NULL)
	{
		idx = 0;
		while (idx < BLOCK_SPACE)
		{
			block_del((*a)[idx]);
			(*a)[idx] = NULL;
			++idx;
		}
		free(*a);
		*a = NULL;
	}
}
