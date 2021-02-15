/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:33:54 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/02/08 16:14:18 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	direction_input(double dir_x, double dir_y, t_global *g)
{
	g->loop.dir_x = dir_x;
	g->loop.dir_y = dir_y;
}

void	direction_input2(double plane_x, double plane_y, t_global *g)
{
	g->loop.plane_x = plane_x;
	g->loop.plane_y = plane_y;
}

void	direction(t_global *g)
{
	char	dir;

	dir = g->mapa.aux[g->mapa.pos_x][g->mapa.pos_y];
	g->mapa.aux[g->mapa.pos_x][g->mapa.pos_y] = '0';
	if (dir == 'N' || dir == 'n')
	{
		direction_input(-1, 0, g);
		direction_input2(0, 0.66, g);
	}
	if (dir == 'S' || dir == 's')
	{
		direction_input(1, 0, g);
		direction_input2(0, -0.66, g);
	}
	if (dir == 'E' || dir == 'e')
	{
		direction_input(0, 1, g);
		direction_input2(0.66, 0, g);
	}
	if (dir == 'W' || dir == 'w')
	{
		direction_input(0, -1, g);
		direction_input2(-0.66, 0, g);
	}
}
