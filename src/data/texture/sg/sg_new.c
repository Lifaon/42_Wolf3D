/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sg_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:50:32 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:50:32 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sg.h"

void	*texture_sg_new(void)
{
	t_texture_sg	*res;

	if ((res = (t_texture_sg *)malloc(sizeof(*res))) != NULL)
	{
		res->color = 0;
	}
	return ((void *)res);
}
