/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 22:20:47 by nlutsevi          #+#    #+#             */
/*   Updated: 2022/02/07 04:25:00 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_res	ft_res(char *line)
{
	char	**aux;
	t_res	res;

	res.x = 0;
	res.y = 0;
	aux = ft_split(line, ' ');
	check_len(aux, 3);
	if (is_digit(aux[1]) && is_digit(aux[2]))
	{
		res.x = atoi(aux[1]);
		res.y = atoi(aux[2]);
	}
	else
		ft_error(RED"Wrong map resolution\n"WHITE);
	res_is_valid(&res);
	free_str(aux);
	return (res);
}

int		check_len(char **aux, int num)
{
	int		i;

	i = 0;
	while (aux[i] != NULL)
		i++;
	if (i != num)
		ft_error(RED"Problem with resolution arguments\n"WHITE);
	return (i);
}

int		is_digit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	res_is_valid(t_res *res)
{
	if (res->x > MAX_RES_WIDTH || res->y > MAX_RES_HEIGHT)
	{
		(res->x = MAX_RES_WIDTH);
		(res->y = MAX_RES_HEIGHT);
	}
	if (res->x < MIN_RES_WIDTH || res->y < MIN_RES_HEIGHT)
	{
		(res->x = MIN_RES_WIDTH);
		(res->y = MIN_RES_HEIGHT);
	}
}

void	free_str(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}
