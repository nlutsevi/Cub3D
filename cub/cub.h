/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 20:07:57 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/02/14 18:02:25 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define DIRECTIONS "NSEW"
# define MAP_CHARACTERS "012NSEW"
# define MAX_RES_WIDTH 2560
# define MAX_RES_HEIGHT 1440
# define MIN_RES_WIDTH 320
# define MIN_RES_HEIGHT 240
# define N_CONFIG 8
# define RED "\033[22;31m"
# define WHITE "\x1b[37m"
# define MOVESPEED 0.05
# define ROTSPEED 0.05
# define K_PRESS 2
# define K_RELEASE 3
# define K_EXIT 17
# define W 13
# define S 1
# define A 0
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53

# include "../gnl/get_next_line.h"
# include "../printf/libft/libft.h"
# include "../printf/ft_printf.h"
# include <stdio.h>
# include "../mlx/mlx.h"
# include "../mlx_beta/mlx.h"
# include <math.h>

typedef struct	s_res
{
	size_t			x;
	size_t			y;
}				t_res;

typedef struct	s_color
{
	int				rgb[3];
	int				rgb_int;
}				t_color;

typedef struct	s_map
{
	int				rows;
	int				columns;
	int				pos_x;
	int				pos_y;
	int				count;
	char			*buff;
	char			**aux;
}				t_map;

typedef struct	s_map_config
{
	int				count;
	t_res			res;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	t_color			floor;
	t_color			ceiling;
}				t_map_config;

typedef struct	s_mlx
{
	void			*mlx;
	void			*win;
}				t_mlx;

typedef struct	s_img
{
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
	int				width;
	int				height;
}				t_img;

typedef struct	s_game
{
	double			pos_x;
	double			pos_y;
	double			camera_x;
	double			raydir_x;
	double			raydir_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	int				map_x;
	int				map_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			old_dir_x;
	double			old_plane_x;
	int				tex_num;
	double			wall_x;
	int				tex_x;
	double			step;
	double			tex_pos;
	int				tex_y;
	int				num_sprites;
	int				*sprite_order;
	double			*sprite_distance;
	double			sprite_x;
	double			sprite_y;
}				t_game;

typedef struct	s_move
{
	int				w;
	int				s;
	int				a;
	int				d;
	int				left;
	int				right;
}				t_move;

typedef struct	s_sprites
{
	double			x;
	double			y;
	int				texture;
	int				num;
}				t_sprites;

typedef struct	s_vector_int
{
	int				x;
	int				y;
}				t_vector_int;

typedef struct	s_casting
{
	t_sprites		sprite;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	int				sprite_screen_x;
	int				sprite_height;
	int				sprite_width;
	int				draw_start_y;
	int				draw_end_y;
	int				draw_start_x;
	int				draw_end_x;
	t_vector_int	texture;
	int				mv_screen;
}				t_casting;

typedef struct	s_bmp
{
	char			byte_type[2];
	int				byte_size;
	int				byte_reserved;
	int				byte_offset;
	int				header_size;
	int				image_width;
	int				image_height;
	int				color_planes;
	int				bits_per_pixel;
	int				compression;
	int				image_size;
	int				bits_xpels_per_meter;
	int				bits_ypels_per_meter;
	int				total_colors;
	int				important_colors;
}				t_bmp;

typedef struct	s_global
{
	t_mlx			mlx;
	t_img			img;
	t_img			*texture;
	t_res			res;
	t_map_config	map;
	t_game			loop;
	t_map			mapa;
	t_move			move;
	int				color;
	unsigned int	*z_buffer;
	t_sprites		*sprites;
	int				bmp;
}				t_global;

t_res			ft_res(char *line);
int				config_inic(char *argv, t_global *g);
int				check_len(char **aux, int num);
int				is_digit(char *str);
void			res_is_valid(t_res *res);
void			free_str(char **str);
char			*ft_texture(char *line);
t_color			ft_color(char *line);
void			ft_read_map(int fd, t_global *g);
char			**right_padding(char **mapa, int i, int y);
void			ft_locate_player(t_map *map);
char			**map_matrix(int rows, char **mapa);
int				ft_error(const char *str);
void			map_is_closed(t_map *map);
int				ft_isspace(int c);
void			loop_camera(t_global *g, int x);
void			direction(t_global *g);
void			initial_side_dist(t_global *g);
void			dda(t_global *g);
void			line_calc(t_global *g);
void			ft_draw(t_global *g, int x);
int				move(t_global *g);
int				move_w(t_global *g);
int				move_s(t_global *g);
int				move_a(t_global *g);
int				move_d(t_global *g);
int				rot_left(t_global *g);
int				rot_right(t_global *g);
int				press(int key, t_global *g);
int				release(int key, t_global *g);
int				closed(t_global *g);
int				loop(t_global *g);
t_img			*init_textures(t_global *g);
void			load_textures(t_global *g);
void			textures_calc(t_global *g);
void			init_sprites(t_global *g);
void			sprite_casting(t_global *g);
void			sprites_calc(t_global *g, int i, t_casting *s_cast);
void			sprites_draw(t_global *g, int start, t_casting *s_cast);
void			flood_fill(char **mapa, t_map *map, int x, int y);
int				screenshot(t_global *g);
void			sprite_sort(t_global *g);
char			**ft_fill_map(t_map *map, char **mapa);
void			ft_read_map2(t_map map, t_global *g);

#endif
