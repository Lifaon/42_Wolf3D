/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:51:18 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:51:19 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

inline int	array_push(t_array *a, void const *src, size_t n_element)
{
	return (array_push_at(a, src, n_element, a->length));
}
