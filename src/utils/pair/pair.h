/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:51:43 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:51:44 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_H
# define PAIR_H

# include <stddef.h>

typedef struct	s_pair
{
	char	*key;
	char	*value;
}				t_pair;

typedef struct	s_pairs
{
	t_pair	**p;
	size_t	length;
	size_t	capacity;
	size_t	p_size;
}				t_pairs;

char			*pair_key_new(const char *s);
char			*pair_value_new(const char *s);

extern void		pair_delete(t_pair **a);
extern char		*pair_get(t_pairs *p, const char *key);
extern t_pair	*pair_new(void);
extern t_pair	*pair_parse(t_pair *a, const char *s);

#endif
