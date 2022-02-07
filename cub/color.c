/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 21:19:14 by nlutsevi          #+#    #+#             */
/*   Updated: 2022/02/07 04:27:40 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_texture(char *line)
{
	char	**str;
	char	*file;

	str = ft_split(line, ' ');
	check_len(str, 2);
	file = strdup(str[1]);
	free_str(str);
	return (file);
}

int		ft_rgb_int(int r, int g, int b)
{
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
	{
		ft_error(RED"Problem with rgb declaration"WHITE);
	}
	return (r << 16 | g << 8 | b);
}

void	color_check(char *line)
{
	int		i;

	i = 0;
	if (line[1] == '\0')
		ft_error(RED"Color is empty\n");
	while (line[++i])
		if (!ft_isdigit(line[i]) && line[i] != ',' && line[i] != ' ' \
			&& line[i] != '\t')
			ft_error(RED"Wrong format in color");
}

t_color	ft_color(char *line)
{
	t_color	color;
	int		i;

	i = 0;
	color_check(line);
	while (i < 3)
	{
		if (line == NULL)
			ft_error(RED"Too few arguments in color");
		line++;
		color.rgb[i] = atoi(&line[0]);
		line = strchr(line, ',');
		if (i == 2 && line != NULL)
		{
			ft_error(RED"Too many arguments in color\n"WHITE);
			i++;
		}
		i++;
	}
	color.rgb_int = ft_rgb_int(color.rgb[0], color.rgb[1], color.rgb[2]);
	return (color);
}
