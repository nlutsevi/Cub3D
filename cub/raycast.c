/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:17:53 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/02/08 17:34:05 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	loop_camera(t_global *g, int x)
{
	g->loop.camera_x = 2 * x / (double)g->map.res.x - 1;
	g->loop.raydir_x = g->loop.dir_x + g->loop.plane_x * g->loop.camera_x;
	g->loop.raydir_y = g->loop.dir_y + g->loop.plane_y * g->loop.camera_x;
	g->loop.map_x = (int)g->loop.pos_x;
	g->loop.map_y = (int)g->loop.pos_y;
	g->loop.deltadist_x = fabs(1 / g->loop.raydir_x);
	g->loop.deltadist_y = fabs(1 / g->loop.raydir_y);
	g->loop.hit = 0;
}

void	initial_side_dist(t_global *g)
{
	if (g->loop.raydir_x < 0)
	{
		g->loop.step_x = -1;
		g->loop.sidedist_x = \
			(g->loop.pos_x - g->loop.map_x) * g->loop.deltadist_x;
	}
	else
	{
		g->loop.step_x = 1;
		g->loop.sidedist_x = \
			(g->loop.map_x + 1.0 - g->loop.pos_x) * g->loop.deltadist_x;
	}
	if (g->loop.raydir_y < 0)
	{
		g->loop.step_y = -1;
		g->loop.sidedist_y = \
			(g->loop.pos_y - g->loop.map_y) * g->loop.deltadist_y;
	}
	else
	{
		g->loop.step_y = 1;
		g->loop.sidedist_y = \
			(g->loop.map_y + 1.0 - g->loop.pos_y) * g->loop.deltadist_y;
	}
}

void	dda(t_global *g)
{
	while (g->loop.hit == 0)
	{
		if (g->loop.sidedist_x < g->loop.sidedist_y)
		{
			g->loop.sidedist_x += g->loop.deltadist_x;
			g->loop.map_x += g->loop.step_x;
			g->loop.side = 0;
		}
		else
		{
			g->loop.sidedist_y += g->loop.deltadist_y;
			g->loop.map_y += g->loop.step_y;
			g->loop.side = 1;
		}
		if (g->mapa.aux[g->loop.map_x][g->loop.map_y] == '1')
			g->loop.hit = 1;
	}
	if (g->loop.side == 0)
		g->loop.perp_wall_dist = (g->loop.map_x - g->loop.pos_x + \
			(1 - g->loop.step_x) / 2) / g->loop.raydir_x;
	else
		g->loop.perp_wall_dist = (g->loop.map_y - g->loop.pos_y + \
			(1 - g->loop.step_y) / 2) / g->loop.raydir_y;
	g->loop.line_height = (int)(g->map.res.y / g->loop.perp_wall_dist);
}

void	line_calc(t_global *g)
{
	g->loop.draw_start = -g->loop.line_height / 2 + g->map.res.y / 2;
	if (g->loop.draw_start < 0)
		g->loop.draw_start = 0;
	g->loop.draw_end = g->loop.line_height / 2 + g->map.res.y / 2;
	if (g->loop.draw_end >= (int)g->map.res.y)
		g->loop.draw_end = g->map.res.y - 1;
}

void	ft_draw(t_global *g, int x)
{
	int i;

	i = 0;
	while (i < g->loop.draw_start)
	{
		*(g->img.data + (i * g->map.res.x) + x) = g->map.ceiling.rgb_int;
		i++;
	}
	while (i < g->loop.draw_end)
	{
		g->loop.tex_y = (int)g->loop.tex_pos & \
			(g->texture[g->loop.tex_num].height - 1);
		g->loop.tex_pos += g->loop.step;
		g->color = g->texture[g->loop.tex_num].data[(int)(g->texture\
			[g->loop.tex_num].height * g->loop.tex_y + g->loop.tex_x)];
		*(g->img.data + (i * g->map.res.x) + x) = g->color;
		i++;
	}
	while (i < (int)g->map.res.y)
	{
		*(g->img.data + (i * g->map.res.x) + x) = g->map.floor.rgb_int;
		i++;
	}
}
