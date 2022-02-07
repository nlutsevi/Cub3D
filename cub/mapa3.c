/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapa3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:05:17 by nlutsevi          #+#    #+#             */
/*   Updated: 2022/02/07 04:24:09 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char		**ft_fill_map(t_map *map, char **mapa)
{
	int			i;
	int			y;
	ssize_t		len;

	i = 0;
	y = strlen(mapa[i]) - 1;
	while (i < map->rows)
	{
		len = map->columns - strlen(mapa[i]);
		while (ft_isspace(mapa[i][y]) && (mapa[i][y - 1] != '1'))
		{
			len++;
			y--;
		}
		if (len)
		{
			mapa = right_padding(mapa, i, y);
		}
		i++;
	}
	return (mapa);
}

char		**map_split(t_map *map)
{
	char		**matrix;
	char		**mapa;

	mapa = ft_split(map->buff, '\n');
	mapa = ft_fill_map(map, mapa);
	matrix = map_matrix(map->rows, mapa);
	return (matrix);
}

void		ft_read_map2(t_map map, t_global *g)
{
	map.aux = map_split(&map);
	ft_locate_player(&map);
	map_is_closed(&map);
	g->mapa = map;
	free(map.buff);
}
