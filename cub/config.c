/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:52:34 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/02/10 18:48:54 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		map_parser(char *line, char *p, t_global *g)
{
	if ((p = ft_strchr(line, 'R')) != NULL && *(p + 1) == ' ')
		g->map.res = ft_res(line);
	else if ((p = ft_strnstr(line, "NO", ft_strlen(line))) != NULL \
		&& *(p + 2) == ' ')
		g->map.no = ft_texture(line);
	else if ((p = ft_strnstr(line, "SO", ft_strlen(line))) != NULL \
		&& *(p + 2) == ' ')
		g->map.so = ft_texture(line);
	else if ((p = ft_strnstr(line, "WE", ft_strlen(line))) != NULL \
		&& *(p + 2) == ' ')
		g->map.we = ft_texture(line);
	else if ((p = ft_strnstr(line, "EA", ft_strlen(line))) != NULL \
		&& *(p + 2) == ' ')
		g->map.ea = ft_texture(line);
	else if ((p = ft_strrchr(line, 'S')) != NULL && *(p + 1) == ' ')
		g->map.s = ft_texture(line);
	else if ((p = ft_strchr(line, 'F')) != NULL && *(p + 1) == ' ')
		g->map.floor = ft_color(line);
	else if ((p = ft_strchr(line, 'C')) != NULL && *(p + 1) == ' ')
		g->map.ceiling = ft_color(line);
	else if (line[0])
		return (1);
	if (!line[0])
		return (0);
	return (0);
}

int		config_inic(char *argv, t_global *g)
{
	int				fd;
	int				count;
	char			*line;
	char			*p;

	p = NULL;
	count = 0;
	fd = open(argv, O_RDONLY);
	if (fd <= 0)
		ft_error(RED"Error while opening fd\n"WHITE);
	while (count < N_CONFIG && get_next_line(fd, &line) > 0)
	{
		if (map_parser(line, p, g) == 1)
			break ;
		free(line);
		line = NULL;
		count++;
	}
	ft_read_map(fd, g);
	if (line)
		free(line);
	close(fd);
	return (1);
}
