/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:48:59 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:48:59 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "block.h"
#include "singletone.h"

size_t	block_length(void)
{
	t_block	**b;
	size_t	i;
	size_t	c;

	b = *singletone_block();
	i = 0;
	c = 0;
	while (i < BLOCK_SPACE)
	{
		if (b[i] != NULL)
			++c;
		++i;
	}
	return (c);
}
