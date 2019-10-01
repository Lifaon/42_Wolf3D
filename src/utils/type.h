/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:53:10 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:53:11 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# include <stddef.h>

struct	s_type
{
	size_t	type;
	void	*node;
};

typedef struct s_type	t_type;

#endif
