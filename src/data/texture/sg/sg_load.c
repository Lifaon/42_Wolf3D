/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sg_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:50:30 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:50:30 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sg.h"
#include "texture.h"
#include "pair.h"
#include "wutils.h"

#include "ft_printf.h"
int		texture_sg_load(void *a, t_pairs *pairs)
{
	t_texture_sg	*sg;
	unsigned char	*s;

	sg = (t_texture_sg *)a;
	s = (unsigned char *)pair_get(pairs, "color");
	if (s == NULL || s[0] != '#')
		return (-3);
	sg->color = ft_atoul_base((const char *)(s + 1), 16);
	return (0);
}
