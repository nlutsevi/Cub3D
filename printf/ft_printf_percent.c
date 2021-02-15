/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:17:35 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/11/05 17:40:22 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_percent(t_struct *list, size_t p)
{
	if (list->flag_m == 1 && list->flag_w > 0)
		ft_printf_percent_minus(list, p);
	else if (list->flag_z == 1 && list->flag_w > 0)
		ft_printf_percent_zero(list, p);
	else if (list->flag_m == 0 && list->flag_z == 0 && list->flag_w > 0)
		ft_printf_percent_width(list, p);
	else
		list->ret += write(1, &p, 1);
}

void	ft_printf_percent_minus(t_struct *list, size_t p)
{
	size_t	w;

	w = list->flag_w;
	list->ret += write(1, &p, 1);
	w--;
	while (w > 0)
	{
		list->ret += write(1, " ", 1);
		w--;
	}
}

void	ft_printf_percent_zero(t_struct *list, size_t p)
{
	size_t	w;

	w = list->flag_w;
	while (w > 1)
	{
		list->ret += write(1, "0", 1);
		w--;
	}
	list->ret += write(1, &p, 1);
}

void	ft_printf_percent_width(t_struct *list, size_t p)
{
	size_t	w;

	w = list->flag_w;
	while (w > 1)
	{
		list->ret += write(1, " ", 1);
		w--;
	}
	list->ret += write(1, &p, 1);
}
