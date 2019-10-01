/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_value_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:51:41 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:51:41 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wutils.h"

char	*pair_value_new(const char *s)
{
	char	*ptr;

	ptr = ft_strchr(s, '=');
	if (ptr != NULL)
		return (ft_strdup(ptr + 1));
	return (NULL);
}
