/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:50:54 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:50:54 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include <stddef.h>
# include "pair.h"
# include "type.h"
# include "mysdl.h"
# define TEXTURE_SPACE 256

enum e_texture_type
{
	T_TEX_NONE = -1,
	T_TEX_LOADED,
	T_TEX_SG,
	T_TEX_SIZE
};

typedef t_type	t_texture;

extern void			texture_del(void *a);
extern int			texture_load(void *a, t_pairs *pairs);
extern void			*texture_new(const size_t type);
extern int			texture_parse(const char **input);
extern t_col		texture_get_color(const t_texture *t,
		const double y, const double x);
extern size_t	texture_length(void);

#endif
