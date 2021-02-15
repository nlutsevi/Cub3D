/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:37:00 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/02/14 16:31:05 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	sprite_casting(t_global *g)
{
	int			i;
	int			start;
	t_casting	s_cast;

	i = 0;
	sprite_sort(g);
	while (i < g->loop.num_sprites)
	{
		sprites_calc(g, i, &s_cast);
		start = s_cast.draw_start_x;
		while (start < s_cast.draw_end_x)
		{
			sprites_draw(g, start, &s_cast);
			start++;
		}
		i++;
	}
}

void	sprites_calc(t_global *g, int i, t_casting *s_cast)
{
	s_cast->sprite.x = g->sprites[g->loop.sprite_order[i]].x - g->loop.pos_x;
	s_cast->sprite.y = g->sprites[g->loop.sprite_order[i]].y - g->loop.pos_y;
	s_cast->inv_det = 1.0 / (g->loop.plane_x * g->loop.dir_y - g->loop.dir_x \
		* g->loop.plane_y);
	s_cast->transform_x = s_cast->inv_det * (g->loop.dir_y * s_cast->sprite.x \
		- g->loop.dir_x * s_cast->sprite.y);
	s_cast->transform_y = s_cast->inv_det * (-g->loop.plane_y * \
		s_cast->sprite.x + g->loop.plane_x * s_cast->sprite.y);
	s_cast->sprite_screen_x = (int)((g->map.res.x / 2) * \
		(1 + s_cast->transform_x / s_cast->transform_y));
	s_cast->sprite_height = abs((int)(g->map.res.y / s_cast->transform_y));
	s_cast->draw_start_y = -s_cast->sprite_height / 2 + g->map.res.y / 2;
	if (s_cast->draw_start_y < 0)
		s_cast->draw_start_y = 0;
	s_cast->draw_end_y = s_cast->sprite_height / 2 + g->map.res.y / 2;
	if (s_cast->draw_end_y >= (int)g->map.res.y)
		s_cast->draw_end_y = g->map.res.y - 1;
	s_cast->sprite_width = abs((int)(g->map.res.y / s_cast->transform_y));
	s_cast->draw_start_x = -s_cast->sprite_width / 2 + s_cast->sprite_screen_x;
	if (s_cast->draw_start_x < 0)
		s_cast->draw_start_x = 0;
	s_cast->draw_end_x = s_cast->sprite_width / 2 + s_cast->sprite_screen_x;
	if (s_cast->draw_end_x >= (int)g->map.res.x)
		s_cast->draw_end_x = g->map.res.x - 1;
}

void	sprites_draw(t_global *g, int start, t_casting *s_cast)
{
	int		y;
	int		d;

	s_cast->texture.x = (int)(256 * (start - (-s_cast->sprite_width / 2 + \
		s_cast->sprite_screen_x)) * g->texture[4].width / \
		s_cast->sprite_width) / 256;
	if (s_cast->transform_y > 0 && start > 0 && start < \
		(int)g->map.res.x && s_cast->transform_y < g->z_buffer[start])
	{
		y = s_cast->draw_start_y;
		while (y < s_cast->draw_end_y)
		{
			d = y * 256 - g->map.res.y * 128 + s_cast->sprite_height * 128;
			s_cast->texture.y = ((d * g->texture[4].height) \
				/ s_cast->sprite_height) / 256;
			g->color = g->texture[4].data[g->texture[4].width \
				* s_cast->texture.y + s_cast->texture.x];
			if (g->color != 0)
			{
				*(g->img.data + (y * g->map.res.x) + start) = g->color;
			}
			y++;
		}
	}
}
