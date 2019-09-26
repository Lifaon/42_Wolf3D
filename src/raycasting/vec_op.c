/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:36:46 by mlantonn          #+#    #+#             */
/*   Updated: 2019/09/19 19:42:45 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

t_vec	vec_add(t_vec u, t_vec v)
{
	u.x += v.x;
	u.y += v.y;
	return (u);
}

t_vec	vec_substract(t_vec u, t_vec v)
{
	u.x -= v.x;
	u.y -= v.y;
	return (u);
}

t_vec	vec_multiply(t_vec u, double t)
{
	u.x *= t;
	u.y *= t;
	return (u);
}

t_vec	vec_normalize(t_vec u)
{
	double	length;
	t_vec	ret;

	length = sqrt((u.x * u.x) + (u.y * u.y));
	ret.x = u.x / length;
	ret.y = u.y / length;
	return (ret);
}
