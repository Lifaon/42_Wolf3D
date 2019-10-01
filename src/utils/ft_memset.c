/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:52:00 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:52:00 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_memset(void *b, const int c, const size_t len)
{
	size_t			i;
	unsigned char	*m;
	unsigned char	l;

	i = 0;
	m = (unsigned char *)b;
	l = (unsigned char)c;
	while (i < len)
	{
		m[i] = l;
		++i;
	}
}
