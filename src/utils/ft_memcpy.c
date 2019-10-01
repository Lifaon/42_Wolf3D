/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:51:54 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:51:55 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *d, const void *s, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;
	size_t			idx;

	dest = (unsigned char *)d;
	src = (unsigned char *)s;
	idx = 0;
	while (idx < n)
	{
		dest[idx] = src[idx];
		++idx;
	}
	return (d);
}
