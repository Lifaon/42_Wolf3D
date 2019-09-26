/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:24:15 by mlantonn          #+#    #+#             */
/*   Updated: 2019/09/26 15:51:39 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

#include "raycasting.h"

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

_Bool	event_loop(t_e *e);

_Bool	update_cam(t_e *e, _Bool key_downs[4]);
_Bool	rotate(t_e *e, double angle, _Bool key_downs[4]);

void	key_event(t_e *e, _Bool key_downs[4], SDL_Event ev);
void	mouse_event(t_e *e, SDL_Event ev);
_Bool	window_event(t_e *e, SDL_Event ev);

#endif
