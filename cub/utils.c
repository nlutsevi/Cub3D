/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 22:00:50 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/02/10 18:59:00 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_error(const char *str)
{
	char	*error_message;

	error_message = ft_strjoin(RED"Error\n"WHITE, str);
	ft_printf(error_message);
	free(error_message);
	exit(1);
}

int		ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}
