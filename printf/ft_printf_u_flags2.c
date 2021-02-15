/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u_flags2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:13:08 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/11/06 18:54:42 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_u_prec_width_aux2(char *d)
{
	while (*d)
		write(1, d++, 1);
}

void	ft_printf_u_prec_width_aux(t_struct *list, char *d, size_t w, size_t p)
{
	if (p >= ft_strlen(d))
	{
		while (w-- > p)
			list->ret += write(1, " ", 1);
		while (p-- > ft_strlen(d))
			list->ret += write(1, "0", 1);
		if (list->flag_p > 0)
			ft_printf_u_prec_width_aux2(d);
		else if (list->flag_p == 0)
			list->ret += write(1, " ", 1);
	}
	else if (p < ft_strlen(d))
	{
		while (w-- > ft_strlen(d))
			list->ret += write(1, " ", 1);
		if (list->flag_p > 0)
			ft_printf_u_prec_width_aux2(d);
		else if (list->flag_p == 0)
			write(1, " ", 1);
	}
}

void	ft_printf_u_prec_width(t_struct *list, char *d)
{
	size_t	w;
	size_t	p;

	w = list->flag_w;
	p = list->flag_p;
	if (w <= p)
	{
		while (p-- > ft_strlen(d))
			list->ret += write(1, "0", 1);
		if (list->flag_p > 0)
		{
			while (*d)
				write(1, d++, 1);
		}
		else if (list->flag_p == 0)
			list->ret += write(1, " ", 1);
	}
	else if (w > p)
		ft_printf_u_prec_width_aux(list, d, w, p);
}

void	ft_printf_u_prec_width_minus_aux\
	(t_struct *list, char *d, size_t w, size_t p)
{
	while (p-- > ft_strlen(d))
	{
		list->ret += write(1, "0", 1);
		w--;
	}
	if (list->flag_p > 0)
	{
		while (*d)
		{
			write(1, d++, 1);
			w--;
		}
	}
	else if (list->flag_p == 0)
	{
		write(1, " ", 1);
		w--;
	}
	while (w > 0)
	{
		list->ret += write(1, " ", 1);
		w--;
	}
}

void	ft_printf_u_prec_width_minus(t_struct *list, char *d)
{
	size_t	w;
	size_t	p;

	w = list->flag_w;
	p = list->flag_p;
	if (w <= p)
	{
		while (p-- > ft_strlen(d))
			list->ret += write(1, "0", 1);
		while (*d)
			write(1, d++, 1);
	}
	else if (w > p)
		ft_printf_u_prec_width_minus_aux(list, d, w, p);
}
