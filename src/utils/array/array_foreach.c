/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_foreach.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:51:09 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:51:10 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

void	array_foreach(t_array *a, void (*callback)())
{
	void	*pos;
	size_t	p_size;
	size_t	idx;
	size_t	max;

	if (callback != NULL)
	{
		pos = a->p;
		p_size = a->p_size;
		max = a->length;
		idx = 0;
		while (idx < max)
		{
			callback(pos, idx, a);
			pos += p_size;
			++idx;
		}
	}
}
