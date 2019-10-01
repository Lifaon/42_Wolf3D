/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_template.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:52:56 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:52:57 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "wutils.h"

static void	*destroy(char **template, size_t idx, const size_t start)
{
	while (--idx != (size_t)(start - 1))
		free(template[idx - start]);
	free(template);
	return (NULL);
}

char		**prepare_template(const unsigned char **f,
		const size_t start, const size_t end)
{
	size_t	line_length;
	size_t	idx;
	char	**template;

	template = NULL;
	if (start < end && (template = (char **)malloc(sizeof(*template)
				* (end - start + 1))) != NULL)
	{
		template[end - start] = 0;
		idx = start;
		while (idx < end)
		{
			line_length = ft_strlen((const char *)f[idx]) + 1;
			template[idx - start] = (char *)malloc(sizeof(**template)
					* line_length);
			if (template[idx - start] != NULL)
				ft_memcpy((void *)template[idx - start],
						(const void *)f[idx], line_length);
			else
				return (destroy(template, idx, start));
			++idx;
		}
	}
	return (template);
}
