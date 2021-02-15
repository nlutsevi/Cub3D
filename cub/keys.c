/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 20:19:20 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/02/08 15:50:46 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		press(int key, t_global *g)
{
	if (key == W || key == UP)
		g->move.w = 1;
	if (key == S || key == DOWN)
		g->move.s = -1;
	if (key == A)
		g->move.a = 1;
	if (key == D)
		g->move.d = -1;
	if (key == LEFT)
		g->move.left = 1;
	if (key == RIGHT)
		g->move.right = 1;
	if (key == ESC)
		closed(g);
	return (0);
}

int		release(int key, t_global *g)
{
	if (key == W || key == UP)
		g->move.w = 0;
	if (key == S || key == DOWN)
		g->move.s = 0;
	if (key == A)
		g->move.a = 0;
	if (key == D)
		g->move.d = 0;
	if (key == LEFT)
		g->move.left = 0;
	if (key == RIGHT)
		g->move.right = 0;
	return (0);
}

int		closed(t_global *g)
{
	mlx_destroy_window(g->mlx.mlx, g->mlx.win);
	system("leaks cub3D");
	exit(0);
	return (0);
}
