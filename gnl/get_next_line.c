/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 18:15:47 by nlutsevi          #+#    #+#             */
/*   Updated: 2022/02/07 04:26:32 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_one_line(char **content, char **line)
{
	*line = strdup(*content);
	free(*content);
	*content = NULL;
	return (0);
}

int		get_new_line(char **content, char **line, int numbytes)
{
	char	*temp;
	char	*temp2;

	if (numbytes < 0)
		return (-1);
	if (numbytes == 0 && !*content)
	{
		*line = strdup("");
		return (0);
	}
	else if ((temp = strchr(*content, '\n')))
	{
		*temp = '\0';
		*line = strdup(*content);
		temp2 = strdup(temp + 1);
		free(*content);
		*content = temp2;
		return (1);
	}
	else if ((strchr(*content, '\0')))
	{
		ft_one_line(&*content, &*line);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*content[FD_SIZE];
	char			*buff;
	char			*temp;
	int				numbytes;

	if ((fd < 0 || line == NULL || BUFF_SIZE < 0 || \
		(!(buff = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))))
		return (-1);
	while ((numbytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[numbytes] = '\0';
		if (!(content[fd]))
			content[fd] = strdup(buff);
		else
		{
			temp = ft_strjoin(content[fd], buff);
			free(content[fd]);
			content[fd] = temp;
		}
		if (strchr(buff, '\n'))
			break ;
	}
	free(buff);
	buff = NULL;
	return (get_new_line(&content[fd], &*line, numbytes));
}
