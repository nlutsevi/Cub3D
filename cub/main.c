/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 19:44:23 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/02/14 18:03:33 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	args_checker(int argc, char **argv, t_global *g)
{
	g->bmp = 0;
	if (argc > 3 || argc <= 1)
		ft_error(RED"Bad number of arguments\n"WHITE);
	if (ft_strlen(argv[1]) < 5)
		ft_error(RED"Wrong file\n"RED);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) > 0)
		ft_error(RED"Not .cub file\n"WHITE);
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 6) != 0)
			ft_error(RED"Third arguments is not --save"WHITE);
		else
		{
			g->bmp = 1;
		}
	}
}

int		init_args(t_global *g)
{
	g->mlx.mlx = mlx_init();
	if (g->bmp == 0)
		g->mlx.win = \
			mlx_new_window(g->mlx.mlx, g->map.res.x, g->map.res.y, "Cub3D");
	g->img.img_ptr = \
		mlx_new_image(g->mlx.mlx, g->map.res.x, g->map.res.y);
	g->img.data = \
	(int*)mlx_get_data_addr(g->img.img_ptr, &g->img.bpp, \
		&g->img.size_l, &g->img.endian);
	return (1);
}

void	init_vars(t_global *g)
{
	g->loop.pos_x = g->mapa.pos_x + 0.5;
	g->loop.pos_y = g->mapa.pos_y + 0.5;
	g->loop.plane_x = 0;
	g->loop.plane_y = 0;
	direction(g);
	g->texture = init_textures(g);
	load_textures(g);
	init_sprites(g);
	g->move.w = 0;
	g->move.s = 0;
	g->move.a = 0;
	g->move.d = 0;
	g->move.left = 0;
	g->move.right = 0;
}

int		loop(t_global *g)
{
	size_t		x;

	x = 0;
	while (x < g->map.res.x)
	{
		loop_camera(g, x);
		initial_side_dist(g);
		dda(g);
		line_calc(g);
		textures_calc(g);
		g->z_buffer[x] = g->loop.perp_wall_dist;
		ft_draw(g, x);
		x++;
	}
	sprite_casting(g);
	if (g->bmp == 0)
		mlx_put_image_to_window(g->mlx.mlx, g->mlx.win, g->img.img_ptr, 0, 0);
	if (g->bmp == 1)
	{
		screenshot(g);
		exit(0);
	}
	move(g);
	return (0);
}

int		main(int argc, char **argv)
{
	t_global	g;

	config_inic(argv[1], &g);
	args_checker(argc, argv, &g);
	init_args(&g);
	init_vars(&g);
	if (g.bmp == 0)
	{
		mlx_hook(g.mlx.win, K_PRESS, 0, &press, &g);
		mlx_hook(g.mlx.win, K_RELEASE, 0, &release, &g);
		mlx_hook(g.mlx.win, K_EXIT, 0L, &closed, &g);
	}
	mlx_loop_hook(g.mlx.mlx, loop, &g);
	mlx_loop(g.mlx.mlx);
	return (0);
}
