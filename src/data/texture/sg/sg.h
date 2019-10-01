/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sg.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:50:34 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:50:35 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SG_H
# define SG_H

# include <stddef.h>
# include "pair.h"

/**
 * @param color
 * 32 bits color ARGB
 *
 * @param a
 * 4th 8 bits aplha color
 *
 * @param r
 * 3rd 8 bits red color
 *
 * @param g
 * 2nd 8 bits green color
 *
 * @param b
 * 1st 8 bits blue color
 */

typedef struct	s_texture_sg
{
	union {
		unsigned int	color;
		struct {
			unsigned char	a;
			unsigned char	r;
			unsigned char	g;
			unsigned char	b;
		};
	};
}				t_texture_sg;

extern void			texture_sg_del(void *a);
extern int			texture_sg_load(void *a, t_pairs *pairs);
extern void			*texture_sg_new(void);
extern unsigned int	texture_sg_get_color(const void *t,
		const double y, const double x);

#endif
