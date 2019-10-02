/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loaded.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:50:21 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:50:21 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOADED_H
# define LOADED_H

# include <stddef.h>
# include "pair.h"

struct				s_col24
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
};

typedef struct		s_texture_loaded
{
	unsigned int	*ibuf;
	size_t			x;
	size_t			y;
}					t_texture_loaded;

extern void			texture_loaded_del(void *a);
extern int			texture_loaded_load(void *a, t_pairs *pairs);
extern void			*texture_loaded_new(void);
extern unsigned int	texture_loaded_get_color(const void *t,
		const double y, const double x);

#endif
