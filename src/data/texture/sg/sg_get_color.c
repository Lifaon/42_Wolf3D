/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sg_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:50:27 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:50:28 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sg.h"

unsigned int	texture_sg_get_color(const void *t,
		const double y, const double x)
{
	t_texture_sg	*s;

	(void)x;
	(void)y;
	s = (t_texture_sg *)t;
	return (s->color);
}
