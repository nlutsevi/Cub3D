/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:46:46 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/02/15 17:24:14 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		move(t_global *g)
{
	if (g->move.w)
		move_w(g);
	if (g->move.s)
		move_s(g);
	if (g->move.a)
		move_a(g);
	if (g->move.d)
		move_d(g);
	if (g->move.left)
		rot_left(g);
	if (g->move.right)
		rot_right(g);
	return (0);
}

int		move_w(t_global *g)
{
	if (g->mapa.aux[(int)(g->loop.pos_x + g->loop.dir_x * MOVESPEED)]\
		[(int)g->loop.pos_y] == '0')
		g->loop.pos_x += g->loop.dir_x * MOVESPEED;
	if (g->mapa.aux[(int)g->loop.pos_x]\
		[(int)(g->loop.pos_y + g->loop.dir_y * MOVESPEED)] == '0')
		g->loop.pos_y += g->loop.dir_y * MOVESPEED;
	return (0);
}

int		move_s(t_global *g)
{
	if (g->mapa.aux[(int)(g->loop.pos_x - g->loop.dir_x * MOVESPEED)]\
		[(int)g->loop.pos_y] == '0')
		g->loop.pos_x -= g->loop.dir_x * MOVESPEED;
	if (g->mapa.aux[(int)g->loop.pos_x]\
		[(int)(g->loop.pos_y - g->loop.dir_y * MOVESPEED)] == '0')
		g->loop.pos_y -= g->loop.dir_y * MOVESPEED;
	return (0);
}

int		move_a(t_global *g)
{
	if (g->mapa.aux[(int)g->loop.pos_x]\
		[(int)(g->loop.pos_y + g->loop.dir_x * MOVESPEED)] == '0')
		g->loop.pos_y += g->loop.dir_x * MOVESPEED;
	if (g->mapa.aux[(int)(g->loop.pos_x - g->loop.dir_y * MOVESPEED)]\
		[(int)g->loop.pos_y] == '0')
		g->loop.pos_x -= g->loop.dir_y * MOVESPEED;
	return (0);
}

int		move_d(t_global *g)
{
	if (g->mapa.aux[(int)g->loop.pos_x]\
		[(int)(g->loop.pos_y - g->loop.dir_x * MOVESPEED)] == '0')
		g->loop.pos_y -= g->loop.dir_x * MOVESPEED;
	if (g->mapa.aux[(int)(g->loop.pos_x + g->loop.dir_y * MOVESPEED)]\
		[(int)g->loop.pos_y] == '0')
		g->loop.pos_x += g->loop.dir_y * MOVESPEED;
	return (0);
}
