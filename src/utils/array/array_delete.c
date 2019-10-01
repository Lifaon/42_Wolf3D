/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:51:03 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:51:04 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

inline void	array_delete(t_array *a, void (*delete_content)())
{
	if (a != NULL)
	{
		array_foreach(a, delete_content);
		free(a->p);
		free(a);
	}
}
