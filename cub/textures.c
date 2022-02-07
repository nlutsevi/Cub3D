/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:31:23 by nlutsevi          #+#    #+#             */
/*   Updated: 2022/02/07 04:30:21 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		text_num_calc(t_global *g)
{
	int		num;

	if (g->loop.raydir_x < 0 && g->loop.side == 0)
		num = 0;
	if (g->loop.raydir_x > 0 && g->loop.side == 0)
		num = 1;
	if (g->loop.raydir_y < 0 && g->loop.side == 1)
		num = 2;
	if (g->loop.raydir_y > 0 && g->loop.side == 1)
		num = 3;
	return (num);
}

void	textures_calc(t_global *g)
{
	g->loop.tex_num = text_num_calc(g);
	if (g->loop.side == 0)
		g->loop.wall_x = g->loop.pos_y + g->loop.perp_wall_dist \
		* g->loop.raydir_y;
	else
		g->loop.wall_x = g->loop.pos_x + g->loop.perp_wall_dist \
		* g->loop.raydir_x;
	g->loop.wall_x -= floor(g->loop.wall_x);
	g->loop.tex_x = (int)(g->loop.wall_x * (double)\
	(g->texture[g->loop.tex_num].width));
	if (g->loop.side == 0 && g->loop.raydir_x > 0)
		g->loop.tex_x = g->texture[g->loop.tex_num].width - g->loop.tex_x - 1;
	if (g->loop.side == 1 && g->loop.raydir_y < 0)
		g->loop.tex_x = g->texture[g->loop.tex_num].width - g->loop.tex_x - 1;
	g->loop.step = 1.0 * g->texture[g->loop.tex_num].height \
	/ g->loop.line_height;
	g->loop.tex_pos = (g->loop.draw_start - g->map.res.y \
	/ 2 + g->loop.line_height / 2) * g->loop.step;
}

void	load_textures(t_global *g)
{
	g->texture[0].data = (int*)mlx_get_data_addr(g->texture[0].img_ptr, \
		&g->texture[0].bpp, &g->texture[0].size_l, &g->texture[0].endian);
	g->texture[1].data = (int*)mlx_get_data_addr(g->texture[1].img_ptr, \
		&g->texture[1].bpp, &g->texture[1].size_l, &g->texture[1].endian);
	g->texture[2].data = (int*)mlx_get_data_addr(g->texture[2].img_ptr, \
		&g->texture[2].bpp, &g->texture[2].size_l, &g->texture[2].endian);
	g->texture[3].data = (int*)mlx_get_data_addr(g->texture[3].img_ptr, \
		&g->texture[3].bpp, &g->texture[3].size_l, &g->texture[3].endian);
	g->texture[4].data = (int*)mlx_get_data_addr(g->texture[4].img_ptr, \
		&g->texture[4].bpp, &g->texture[4].size_l, &g->texture[4].endian);
}

void	tex_size_check(t_img *texture, t_global *g)
{
	if (texture[0].width > (int)g->map.res.x || \
		texture[0].height > (int)g->map.res.y)
		ft_error(RED"Texture NO size is too high, \
			texture can´t be loaded."WHITE);
	if (texture[1].width > (int)g->map.res.x || \
		texture[1].height > (int)g->map.res.y)
		ft_error(RED"Texture SO size is too high, \
			texture can´t be loaded."WHITE);
	if (texture[2].width > (int)g->map.res.x || \
		texture[2].height > (int)g->map.res.y)
		ft_error(RED"Texture WE size is too high, \
			texture can´t be loaded."WHITE);
	if (texture[3].width > (int)g->map.res.x || \
		texture[3].height > (int)g->map.res.y)
		ft_error(RED"Texture EA size is too high, \
			texture can´t be loaded."WHITE);
}

t_img	*init_textures(t_global *g)
{
	t_img	*texture;

	texture = malloc(sizeof(t_img) * 5);
	bzero(texture, sizeof(t_img));
	if (!(texture[0].img_ptr = mlx_xpm_file_to_image(g->mlx.mlx, \
	g->map.no, &texture[0].width, &texture[0].height)))
		ft_error(RED"Can't open NO texture!"WHITE);
	if (!(texture[1].img_ptr = mlx_xpm_file_to_image(g->mlx.mlx, \
	g->map.so, &texture[1].width, &texture[1].height)))
		ft_error(RED"Can't open SO texture!"WHITE);
	if (!(texture[2].img_ptr = mlx_xpm_file_to_image(g->mlx.mlx, \
	g->map.we, &texture[2].width, &texture[2].height)))
		ft_error(RED"Can't open NO texture!"WHITE);
	if (!(texture[3].img_ptr = mlx_xpm_file_to_image(g->mlx.mlx, \
	g->map.ea, &texture[3].width, &texture[3].height)))
		ft_error(RED"Can't open NO texture!"WHITE);
	if (!(texture[4].img_ptr = mlx_xpm_file_to_image(g->mlx.mlx, \
	g->map.s, &texture[4].width, &texture[4].height)))
		ft_error(RED"Can't open Sprite texture!"WHITE);
	tex_size_check(texture, g);
	return (texture);
}
