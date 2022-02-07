/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapa2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 18:44:24 by nlutsevi          #+#    #+#             */
/*   Updated: 2022/02/07 04:30:05 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	**right_padding(char **mapa, int i, int y)
{
	y = strlen(mapa[i]) - 1;
	while (ft_isspace(mapa[i][y]) && mapa[i][y - 1] != '1')
	{
		mapa[i][y] = '\0';
		y--;
	}
	if (ft_isspace(mapa[i][y]))
		mapa[i][y] = '\0';
	i++;
	return (mapa);
}

void	ft_locate_player(t_map *map)
{
	int		i;
	int		j;
	int		located;

	i = 0;
	located = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			if (map->aux[i][j] == 'N' || map->aux[i][j] == 'S' \
				|| map->aux[i][j] == 'E' || map->aux[i][j] == 'W')
			{
				located += 1;
				map->pos_x = i;
				map->pos_y = j;
			}
			j++;
		}
		i++;
	}
	if (located != 1)
		ft_error(RED"Wrong number of players\n"WHITE);
}

char	**map_matrix(int rows, char **mapa)
{
	char	**matrix;
	int		i;

	i = 0;
	matrix = (char**)malloc(sizeof(char*) * (rows + 1));
	while (i < rows)
	{
		matrix[i] = strdup(mapa[i]);
		free(mapa[i]);
		i++;
	}
	matrix[i] = NULL;
	free(mapa);
	return (matrix);
}

void	flood_fill(char **mapa, t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->rows || y >= (int)strlen(mapa[x]))
		ft_error(RED"Map is not closed!"WHITE);
	if (ft_isspace(mapa[x][y]) || mapa[x][y] == '0' ||\
		mapa[x][y] == '2' || mapa[x][y] == 'N' || mapa[x][y] == 'S' ||\
		mapa[x][y] == 'E' || mapa[x][y] == 'W')
	{
		mapa[x][y] = '*';
		flood_fill(mapa, map, x + 1, y);
		flood_fill(mapa, map, x, y + 1);
		flood_fill(mapa, map, x - 1, y);
		flood_fill(mapa, map, x, y - 1);
	}
}

void	map_is_closed(t_map *map)
{
	int		x;
	int		y;
	int		i;
	char	**mapa;

	i = 0;
	x = map->pos_x;
	y = map->pos_y;
	mapa = (char**)malloc(sizeof(char*) * (map->rows + 1));
	while (i < map->rows)
	{
		mapa[i] = strdup(map->aux[i]);
		i++;
	}
	mapa[i] = NULL;
	flood_fill(mapa, map, x, y);
	free_str(mapa);
}
