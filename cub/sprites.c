/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 13:18:43 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/02/14 18:37:16 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			num_sprites(t_global *g)
{
	int			x;
	int			y;
	int			num;

	x = 0;
	num = 0;
	while (x < g->mapa.rows)
	{
		y = 0;
		while (y < g->mapa.columns)
		{
			if (g->mapa.aux[x][y] == '2')
				num++;
			y++;
		}
		x++;
	}
	return (num);
}

t_sprites	*alloc_sprites(t_global *g)
{
	t_sprites	*sprites;
	int			x;
	int			y;
	int			count;

	x = 0;
	count = 0;
	sprites = malloc(sizeof(t_sprites) * g->loop.num_sprites);
	while (x < g->mapa.rows)
	{
		y = 0;
		while (y < g->mapa.columns)
		{
			if (g->mapa.aux[x][y] == '2')
			{
				sprites[count].x = x + 0.5;
				sprites[count].y = y + 0.5;
				count++;
			}
			y++;
		}
		x++;
	}
	return (sprites);
}

void		init_sprites(t_global *g)
{
	g->loop.num_sprites = num_sprites(g);
	g->sprites = alloc_sprites(g);
	g->z_buffer = malloc(sizeof(unsigned int) * g->map.res.x);
	g->loop.sprite_order = malloc(sizeof(int) * g->loop.num_sprites);
	g->loop.sprite_distance = malloc(sizeof(double) * g->loop.num_sprites);
}

void		sprite_sort_loop(t_global *g)
{
	int			i;
	int			tmp;
	float		tmp2;

	i = 0;
	while (i < g->loop.num_sprites)
	{
		if (g->loop.sprite_distance[i] < g->loop.sprite_distance[i + 1])
		{
			tmp = g->loop.sprite_order[i];
			g->loop.sprite_order[i] = g->loop.sprite_order[i + 1];
			g->loop.sprite_order[i + 1] = tmp;
			tmp2 = g->loop.sprite_distance[i];
			g->loop.sprite_distance[i] = g->loop.sprite_distance[i + 1];
			g->loop.sprite_distance[i + 1] = tmp2;
			i = 0;
		}
		else
			i++;
	}
}

void		sprite_sort(t_global *g)
{
	int			i;

	i = 0;
	while (i < g->loop.num_sprites)
	{
		g->loop.sprite_order[i] = i;
		g->loop.sprite_distance[i] = sqrt((pow((g->loop.pos_x - \
			g->sprites[i].x), 2)) + pow((g->loop.pos_y - g->sprites[i].y), 2));
		i++;
	}
	sprite_sort_loop(g);
}
