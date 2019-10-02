/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:51:56 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:51:56 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dst_cpy;
	const char	*src_cpy;

	i = 0;
	dst_cpy = (char *)dst;
	src_cpy = (const char *)src;
	if (dst_cpy < src_cpy)
	{
		while (i < len)
		{
			dst_cpy[i] = src_cpy[i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			dst_cpy[len - 1] = src_cpy[len - 1];
			len--;
		}
	}
	return (dst);
}
