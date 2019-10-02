/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:51:11 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:51:12 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

static void	*on_error(t_array *a, void (*del)(void *, size_t))
{
	array_delete(a, del);
	return (NULL);
}

t_array		*array_map(t_array *a,
		void *(*callback)(), void (*del)(void *, size_t))
{
	t_array	*mapped;
	void	*pos;
	void	*ret;
	size_t	idx;
	size_t	max;

	mapped = NULL;
	if (callback == NULL || (mapped = array_new(a->p_size)) == NULL
			|| array_realloc(mapped, a->length, a->p_size) == EXIT_FAILURE)
		return (on_error(mapped, NULL));
	pos = a->p;
	max = a->length;
	idx = 0;
	while (idx < max)
	{
		if ((ret = callback(pos, idx, a)) == NULL
				|| array_push(mapped, &ret, 1) == EXIT_FAILURE)
			return (on_error(mapped, del));
		pos += a->p_size;
		++idx;
	}
	return (mapped);
}
