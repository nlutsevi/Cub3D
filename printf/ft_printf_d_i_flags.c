/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_i_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:35:41 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/11/07 20:25:21 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_d_i_width(t_struct *list, char *d)
{
	size_t	w;

	w = list->flag_w;
	while (w > ft_strlen(d))
	{
		list->ret += write(1, " ", 1);
		w--;
	}
	if (d[0] == '-')
	{
		write(1, "-", 1);
		d++;
	}
	while (*d)
	{
		write(1, d, 1);
		d++;
	}
}

void		ft_printf_d_i_minus(t_struct *list, char *d)
{
	size_t	w;

	w = list->flag_w;
	if (d[0] == '-')
	{
		write(1, "-", 1);
		d++;
		w--;
	}
	if (w > ft_strlen(d))
	{
		while (*d)
		{
			write(1, d, 1);
			d++;
			w--;
		}
		while (w-- > 0)
			list->ret += write(1, " ", 1);
	}
	else
	{
		while (*d)
			write(1, d++, 1);
	}
}

void		ft_printf_d_i_zero(t_struct *list, char *d)
{
	size_t	w;

	w = list->flag_w;
	if (d[0] == '-')
	{
		write(1, "-", 1);
		d++;
		w--;
	}
	while (w > ft_strlen(d))
	{
		list->ret += write(1, "0", 1);
		w--;
	}
	while (*d)
	{
		write(1, d, 1);
		d++;
	}
}

void		ft_printf_d_i_precision(t_struct *list, char *d)
{
	size_t	p;

	p = list->flag_p;
	if (p == 0)
		list->ret = 0;
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
}
