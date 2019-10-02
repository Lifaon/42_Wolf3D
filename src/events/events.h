/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:24:15 by mlantonn          #+#    #+#             */
/*   Updated: 2019/10/02 09:44:13 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "raycasting.h"

# define W 0
# define S 1
# define A 2
# define D 3
# define LEFT 4
# define RIGHT 5
# define SHIFT 6

_Bool	event_loop(t_e *e);

_Bool	update_cam(t_e *e, _Bool key_downs[7]);
void	rotate(t_e *e, double angle, _Bool key_downs[7]);

void	key_event(t_e *e, _Bool key_downs[7], SDL_Event ev);
void	mouse_event(t_e *e, SDL_Event ev);
_Bool	window_event(t_e *e, SDL_Event ev);

#endif
