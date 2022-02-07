/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 22:00:50 by nlutsevi          #+#    #+#             */
/*   Updated: 2022/02/07 04:31:12 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_error(const char *str)
{
	char	*error_message;

	error_message = ft_strjoin(RED"Error\n"WHITE, str);
	printf("%s", error_message);
	free(error_message);
	exit(1);
}

int		ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int		ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}
