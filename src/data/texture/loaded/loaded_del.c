/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loaded_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:50:11 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:50:12 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "loaded.h"

void	texture_loaded_del(void *a)
{
	t_texture_loaded	*b;

	b = (t_texture_loaded *)a;
	if (b != NULL)
	{
		free(b->ibuf);
		free(b);
	}
}
