/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:52:38 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:52:39 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "wutils.h"

char	*ft_strcdup(const char *s, const int c)
{
	char	*res;
	char	*ptr;
	size_t	len;

	ptr = ft_strchr(s, c);
	if (ptr == NULL)
		return (ft_strdup(s));
	len = (size_t)(ptr - s);
	res = malloc(sizeof(char) * (len + 1));
	if (res != NULL)
	{
		ft_memcpy(res, s, len);
		res[len] = 0;
	}
	return (res);
}
