/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 10:50:30 by mlantonn          #+#    #+#             */
/*   Updated: 2019/09/30 10:50:45 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	*draw_thread(void *arg)
{
	pthread_t	current;
	t_e			*e;
	t_vec		ray;
	int			x;
	int			i;

	current = pthread_self();
	e = (t_e *)arg;
	i = 0;
	while (current != e->thread[i])
		++i;
	x = i * e->sdl.w / NB_THR - 1;
	i = (i + 1) * e->sdl.w / NB_THR;
	while (++x < i)
	{
		ray = vec_add(e->cam.dir,
			vec_multiply(e->cam.plane, 1 - (x / (double)(e->sdl.w / 2))));
		process_ray(e, ray, e->cam.pos_i, x);
	}
	pthread_exit(NULL);
}

_Bool		raycasting(t_e *e)
{
	int			i;
	int			j;

	i = -1;
	while (++i < NB_THR)
	{
		if (pthread_create(&e->thread[i], NULL, &draw_thread, e))
		{
			ft_dprintf(2, "Could not create needed thread(s): %s\n",
				strerror(errno));
			j = -1;
			while (++j < i)
				pthread_cancel(e->thread[j]);
			return (EXIT_FAILURE);
		}
	}
	i = -1;
	while (++i < NB_THR)
		pthread_join(e->thread[i], NULL);
	print_tex(&e->sdl);
	return (EXIT_SUCCESS);
}
