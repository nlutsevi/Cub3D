/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 19:28:57 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/11/08 20:35:03 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_u_count(unsigned int nb)
{
	unsigned int	i;

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

void	ft_printf_u_aux(char *d)
{
	while (*d)
	{
		write(1, d, 1);
		d++;
	}
}

void	ft_printf_u(t_struct *list, unsigned int nb)
{
	char	*d;

	list->ret += ft_printf_u_count(nb);
	d = ft_itoa_base(nb, 10);
	if (list->flag_w > 0 && list->flag_m == 0 && list->flag_z == 0 \
		&& list->flag_p == -1)
		ft_printf_u_width(list, d);
	else if (list->flag_w > 0 && list->flag_m == 1 && list->flag_p == -1)
		ft_printf_u_minus(list, d);
	else if (list->flag_w > 0 && list->flag_z == 1 && list->flag_p == -1)
		ft_printf_u_zero(list, d);
	else if (list->flag_p > -1 && list->flag_m == 0 && list->flag_z == 0 \
		&& list->flag_w == 0)
		ft_printf_u_precision(list, d);
	else if (list->flag_w > 0 && list->flag_p > -1 && list->flag_m == 0 \
		&& list->flag_z == 0)
		ft_printf_u_prec_width(list, d);
	else if (list->flag_p > -1 && list->flag_w > 0 && list->flag_m == 1)
		ft_printf_u_prec_width_minus(list, d);
	else if (list->flag_p > -1 && list->flag_w > 0 && list->flag_z == 1)
		ft_printf_u_prec_width(list, d);
	else
		ft_printf_u_aux(d);
	free(d);
}
