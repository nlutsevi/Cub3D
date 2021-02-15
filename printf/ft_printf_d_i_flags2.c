/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_i_flags2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:52:46 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/11/07 20:25:32 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_d_i_prec_width_aux(t_struct *list, char *d, size_t p)
{
	if (d[0] == '-')
	{
		write(1, "-", 1);
		d++;
	}
	while (p > ft_strlen(d))
	{
		list->ret += write(1, "0", 1);
		p--;
	}
	if (list->flag_p > 0)
	{
		while (*d)
		{
			write(1, d, 1);
			d++;
		}
	}
	else if (list->flag_p == 0)
		list->ret += write(1, " ", 1);
}

void		ft_printf_d_i_prec_width_aux2\
	(t_struct *list, char *d, size_t w, size_t p)
{
	if (d[0] == '-')
	{
		while (w-- > (p + 1))
			list->ret += write(1, " ", 1);
		write(1, "-", 1);
		d++;
	}
	else
	{
		while (w-- > p)
			list->ret += write(1, " ", 1);
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

void		ft_printf_d_i_prec_width_aux3(char *d)
{
	while (*d)
	{
		write(1, d, 1);
		d++;
	}
}

void		ft_printf_d_i_prec_width(t_struct *list, char *d)
{
	size_t	w;
	size_t	p;

	w = list->flag_w;
	p = list->flag_p;
	if (w <= p)
		ft_printf_d_i_prec_width_aux(list, d, p);
	else if (w > p)
	{
		if (p >= ft_strlen(d))
			ft_printf_d_i_prec_width_aux2(list, d, w, p);
		else if (p < ft_strlen(d))
		{
			while (w > ft_strlen(d))
			{
				list->ret += write(1, " ", 1);
				w--;
			}
			if (list->flag_p > 0)
				ft_printf_d_i_prec_width_aux3(d);
			else if (list->flag_p == 0)
				write(1, " ", 1);
		}
	}
}
