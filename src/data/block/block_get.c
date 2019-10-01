/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:48:55 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:48:56 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "block.h"
#include "singletone.h"

t_block	*block_get(const unsigned char id)
{
	t_block	*b;

	b = (*singletone_block())[(unsigned int)id];
	return (b);
}
