/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:52:49 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:52:50 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n)
		++i;
	return ((i == n) ? 0 : (unsigned char)s1[i] - (unsigned char)s2[i]);
}
