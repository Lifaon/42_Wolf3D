/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:51:25 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:51:25 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <stdlib.h>

typedef struct	s_array
{
	void	*p;
	size_t	length;
	size_t	capacity;
	size_t	p_size;
}				t_array;

extern void		array_delete(t_array *a, void (*delete_content)());
extern void		*array_find(t_array *a,
		int (*cmp)(void *, void *), void *to_find);
extern size_t	array_find_index(t_array *a,
		int (*cmp)(void *, void *), void *to_find);
extern void		array_foreach(t_array *a, void (*callback)());
extern t_array	*array_map(t_array *a, void *(*callback)(),
		void (*del)(void *, size_t));
extern t_array	*array_new(size_t p_size);
extern int		array_push(t_array *a, void const *src, size_t n_element);
extern int		array_push_at(t_array *a, void const *src, size_t n_element,
					size_t const at);
extern int		array_realloc(t_array *a, size_t length, size_t p_size);
extern void		array_show(t_array *a);
#endif
