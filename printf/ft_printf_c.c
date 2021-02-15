/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:19:37 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/11/02 19:44:11 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_c(t_struct *list, int c)
{
	if (list->flag_w > 0 && list->flag_m == 0 && list->flag_z == 0)
		ft_printf_c_width(list, c);
	else if (list->flag_w > 0 && list->flag_m == 1)
		ft_printf_c_minus(list, c);
	else
	{
		list->ret += write(1, &c, 1);
	}
}

void		ft_printf_c_width(t_struct *list, int c)
{
	int		w;

	w = list->flag_w;
	while (w != 1)
	{
		list->ret += write(1, " ", 1);
		w--;
	}
	list->ret += write(1, &c, 1);
}

void		ft_printf_c_minus(t_struct *list, int c)
{
	int		w;

	w = list->flag_w;
	list->ret += write(1, &c, 1);
	while (w != 1)
	{
		list->ret += write(1, " ", 1);
		w--;
	}
}
