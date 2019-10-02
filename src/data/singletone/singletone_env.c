/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singletone_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:49:55 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:49:56 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env.h"
#include "wutils.h"

t_env	***singletone_env(void)
{
	static t_env	**a = NULL;

	if (a == NULL)
	{
		a = (t_env **)malloc(sizeof(t_env *) * ENV_SPACE);
		if (a != NULL)
			ft_memset((void *)a, 0, sizeof(t_env *) * ENV_SPACE);
	}
	return (&a);
}

void	singletone_env_del(void)
{
	t_env	***a;
	size_t	idx;

	a = singletone_env();
	if (*a != NULL)
	{
		idx = 0;
		while (idx < ENV_SPACE)
		{
			env_del((*a)[idx]);
			(*a)[idx] = NULL;
			++idx;
		}
		free(*a);
		*a = NULL;
	}
}
