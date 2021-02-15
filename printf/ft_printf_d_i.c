/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:14:01 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/11/08 20:28:56 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count(long nb)
{
	size_t	i;

	i = 0;
	if (nb == 0)
	{
		return (1);
		i++;
	}
	else if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

void	ft_printf_d_i_aux(char *d)
{
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

void	ft_printf_d_i(t_struct *list, int nb)
{
	char	*d;

	list->ret += ft_count(nb);
	d = ft_itoa(nb);
	if (list->flag_w > 0 && list->flag_m == 0 && list->flag_z == 0 \
	&& list->flag_p <= -1)
		ft_printf_d_i_width(list, d);
	else if (list->flag_w > 0 && list->flag_m == 1 && list->flag_p <= -1)
		ft_printf_d_i_minus(list, d);
	else if (list->flag_w > 0 && list->flag_z == 1 && list->flag_p <= -1)
		ft_printf_d_i_zero(list, d);
	else if (list->flag_p > -1 && list->flag_m == 0 && list->flag_z == 0 \
	&& list->flag_w == 0)
		ft_printf_d_i_precision(list, d);
	else if (list->flag_p > -1 && list->flag_w > 0 && list->flag_m == 0 \
	&& list->flag_z == 0)
		ft_printf_d_i_prec_width(list, d);
	else if (list->flag_p > -1 && list->flag_w > 0 && list->flag_m == 1)
		ft_printf_d_i_prec_width_minus(list, d);
	else if (list->flag_p > -1 && list->flag_w > 0 && list->flag_z == 1)
		ft_printf_d_i_prec_width(list, d);
	else
		ft_printf_d_i_aux(d);
	free(d);
}
