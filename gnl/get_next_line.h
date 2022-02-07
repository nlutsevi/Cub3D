/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 17:25:33 by nlutsevi          #+#    #+#             */
/*   Updated: 2022/02/07 02:20:52 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10
# define FD_SIZE 4096

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>
# include "../printf/libft/libft.h"

int		get_next_line(int fd, char **line);

#endif
