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

typedef struct		s_texture_sg
{
	unsigned int	color;
}					t_texture_sg;

extern void			texture_sg_del(void *a);
extern int			texture_sg_load(void *a, t_pairs *pairs);
extern void			*texture_sg_new(void);
extern unsigned int	texture_sg_get_color(const void *t,
		const double y, const double x);

#endif
