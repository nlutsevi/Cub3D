/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_i_flags3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:18:32 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/11/06 18:15:01 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_d_i_prec_width_minus_aux\
	(t_struct *list, char *d, size_t p)
{
	if (d[0] == '-')
	{
		write(1, "-", 1);
		d++;
	}
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

void		ft_printf_d_i_prec_width_minus_aux2\
	(t_struct *list, char *d, size_t w, size_t p)
{
	write(1, "-", 1);
	d++;
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
		list->ret += write(1, " ", 1);
	while ((w - 1) > 0)
	{
		list->ret += write(1, " ", 1);
		w--;
	}
}

void		ft_printf_d_i_prec_width_minus_aux3\
	(t_struct *list, char *d, size_t w, size_t p)
{
	if (p == 0)
		list->ret = 0;
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
	while (w-- > 0)
		list->ret += write(1, " ", 1);
}

void		ft_printf_d_i_prec_width_minus(t_struct *list, char *d)
{
	size_t	w;
	size_t	p;

	w = list->flag_w;
	p = list->flag_p;
	if (w <= p)
		ft_printf_d_i_prec_width_minus_aux(list, d, p);
	else if (w > p)
	{
		if (d[0] == '-')
			ft_printf_d_i_prec_width_minus_aux2(list, d, w, p);
		else
			ft_printf_d_i_prec_width_minus_aux3(list, d, w, p);
	}
}
