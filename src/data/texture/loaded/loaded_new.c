/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loaded_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:50:18 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:50:18 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "loaded.h"

void	*texture_loaded_new(void)
{
	t_texture_loaded	*res;

	if ((res = (t_texture_loaded *)malloc(sizeof(*res))) != NULL)
	{
		res->ibuf = NULL;
		res->x = 0;
		res->y = 0;
	}
	return ((void *)res);
}
