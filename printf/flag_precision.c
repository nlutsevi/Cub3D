/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 19:05:39 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/11/07 18:13:37 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_precision(t_struct *list)
{
	char	*aux;
	int		x;

	x = 0;
	aux = (char*)calloc(ft_strlen(list->str), sizeof(char));
	list->i++;
	if (ft_isdigit(list->str[list->i]) == 0)
		list->flag_p = 0;
	else
	{
		while (ft_isdigit(list->str[list->i]) == 1)
		{
			aux[x] = list->str[list->i];
			list->i++;
			x++;
		}
	}
	list->flag_p = ft_atoi(aux);
	free(aux);
	if (list->str[list->i] == '*')
	{
		list->flag_p = va_arg(list->args, int);
		list->i++;
	}
}
