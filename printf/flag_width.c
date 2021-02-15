/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 19:50:50 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/11/03 17:13:28 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		flag_width_aux(t_struct *list)
{
	list->flag_m = 1;
	list->flag_w *= -1;
}

void		flag_width(t_struct *list)
{
	char	*aux;
	int		x;

	x = 0;
	aux = (char*)calloc(ft_strlen(list->str), sizeof(char));
	while (ft_isdigit(list->str[list->i]) == 1)
	{
		if (list->str[list->i] >= '0' && list->str[list->i] <= '9')
		{
			aux[x] = list->str[list->i];
			x++;
		}
		list->i++;
	}
	list->flag_w = ft_atoi(aux);
	free(aux);
	if (list->str[list->i] == '*')
	{
		list->flag_w = va_arg(list->args, int);
		list->i++;
	}
	if (list->flag_w < 0)
		flag_width_aux(list);
}
