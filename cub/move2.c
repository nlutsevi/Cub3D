/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:05:22 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/02/08 16:08:13 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		rot_left(t_global *g)
{
	g->loop.old_dir_x = g->loop.dir_x;
	g->loop.dir_x = \
		g->loop.dir_x * cos(ROTSPEED) - g->loop.dir_y * sin(ROTSPEED);
	g->loop.dir_y = \
		g->loop.old_dir_x * sin(ROTSPEED) + g->loop.dir_y * cos(ROTSPEED);
	g->loop.old_plane_x = g->loop.plane_x;
	g->loop.plane_x = \
		g->loop.plane_x * cos(ROTSPEED) - g->loop.plane_y * sin(ROTSPEED);
	g->loop.plane_y = \
		g->loop.old_plane_x * sin(ROTSPEED) + g->loop.plane_y * cos(ROTSPEED);
	return (0);
}

int		rot_right(t_global *g)
{
	g->loop.old_dir_x = g->loop.dir_x;
	g->loop.dir_x = \
		g->loop.dir_x * cos(-ROTSPEED) - g->loop.dir_y * sin(-ROTSPEED);
	g->loop.dir_y = \
		g->loop.old_dir_x * sin(-ROTSPEED) + g->loop.dir_y * cos(-ROTSPEED);
	g->loop.old_plane_x = g->loop.plane_x;
	g->loop.plane_x = \
		g->loop.plane_x * cos(-ROTSPEED) - g->loop.plane_y * sin(-ROTSPEED);
	g->loop.plane_y = \
		g->loop.old_plane_x * sin(-ROTSPEED) + g->loop.plane_y * cos(-ROTSPEED);
	return (0);
}
