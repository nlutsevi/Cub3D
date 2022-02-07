/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 19:58:10 by nlutsevi          #+#    #+#             */
/*   Updated: 2022/02/07 04:23:19 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			valid_map(char *line)
{
	size_t		i;

	i = 0;
	if (!*line)
		return (0);
	while (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || \
			line[i] == 'E' || ft_isspace(line[i]) || line[i] == '1' || \
			line[i] == '0' || line[i] == '2')
		i++;
	if (i == strlen(line))
		return (1);
	else
		ft_error(RED"Map is wrong\n"WHITE);
	return (0);
}

void		map_calculation(char *line, int ret, t_map *map)
{
	int			len;
	char		*aux;
	char		*aux2;

	len = 0;
	aux = NULL;
	aux2 = NULL;
	if (valid_map(line))
	{
		aux = ft_strjoin(map->buff, line);
		free(map->buff);
		map->buff = aux;
		if (ret >= 0)
		{
			aux2 = ft_strjoin(map->buff, "\n");
			map->buff = aux2;
			map->rows++;
		}
		len = strlen(line);
		if (len > map->columns)
			map->columns = len;
		free(aux);
	}
}

void		ft_map_exists(int ret, int line_count, char *line)
{
	if (ret == 0 && line_count == 0)
	{
		free(line);
		ft_error(RED"Map is not provided!"WHITE);
	}
}

void		ft_read_map(int fd, t_global *g)
{
	int			frstline;
	int			line_count;
	t_map		map;
	int			ret;
	char		*line;

	map.rows = 0;
	map.columns = 0;
	frstline = 0;
	line_count = 0;
	map.buff = strdup("");
	while ((ret = get_next_line(fd, &line)) >= 0)
	{
		ft_map_exists(ret, line_count, line);
		if (valid_map(line) == 1)
			frstline = 1;
		if (frstline == 1)
			map_calculation(line, ret, &map);
		free(line);
		line = NULL;
		line_count++;
		if (!ret)
			break ;
	}
	ft_read_map2(map, g);
}
