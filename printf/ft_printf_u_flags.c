/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 19:38:13 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/11/06 18:49:54 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_u_width(t_struct *list, char *d)
{
	size_t	w;

	w = list->flag_w;
	while (w > ft_strlen(d))
	{
		list->ret += write(1, " ", 1);
		w--;
	}
	while (*d)
	{
		write(1, d, 1);
		d++;
	}
}

void	ft_printf_u_minus(t_struct *list, char *d)
{
	size_t	w;

	w = list->flag_w;
	if (w > ft_strlen(d))
	{
		while (*d)
		{
			write(1, d, 1);
			d++;
			w--;
		}
		while (w > 0)
		{
			list->ret += write(1, " ", 1);
			w--;
		}
	}
	else
	{
		while (*d)
			write(1, d++, 1);
	}
}

void	ft_printf_u_zero(t_struct *list, char *d)
{
	size_t	w;

	w = list->flag_w;
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

void	ft_printf_u_precision(t_struct *list, char *d)
{
	size_t	p;

	p = list->flag_p;
	if (p == 0)
		list->ret = 0;
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
