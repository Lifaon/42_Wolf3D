/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loaded_get_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:50:13 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:50:14 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loaded.h"

static double lerp(const double norm, const double min, const double max)
{
	return ((max - min) * norm + min);
}

unsigned int	texture_loaded_get_color(const void *t,
		const double y, const double x)
{
	t_texture_loaded	*l;
	int					xb;
	int					yb;

	l = (t_texture_loaded *)t;
	if (x < 0 || y < 0 || x > 1.0 || y > 1.0)
		return (0);
	xb = lerp(x, 0.0, l->x);
	yb = lerp(y, 0.0, l->y);
	return (l->ibuf[xb + yb * l->x]);
}
