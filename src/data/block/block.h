/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:49:11 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:49:11 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLOCK_H
# define BLOCK_H

# include <stddef.h>
# define BLOCK_SPACE 256

enum	e_block_type
{
	T_BL_NONE = -1,
	T_BL_VOID,
	T_BL_WALL,
	T_BL_SIZE
};

typedef struct	s_block
{
	size_t			type;
	unsigned int	tex_north;
	unsigned int	tex_south;
	unsigned int	tex_east;
	unsigned int	tex_west;
}				t_block;

int				block_parse_pairs(t_block *b, void *pairs_p);

extern void		block_del(void *a);
extern t_block	*block_get(const unsigned char id);
extern void		*block_new(void);
extern int		block_parse(const char **input);
extern size_t	block_length(void);

#endif
