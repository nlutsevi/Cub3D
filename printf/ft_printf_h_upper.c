/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_h_upper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:01:18 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/11/09 17:48:02 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_hexa_aux(t_struct *list, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		list->ret += write(1, &str[i], 1);
		i++;
	}
}

void	ft_printf_hexa_upper(t_struct *list, unsigned int h)
{
	long	value;
	char	*str;

	value = (long)h;
	str = ft_itoa_base(value, 16);
	if (list->flag_w > 0 && list->flag_m == 0 && list->flag_z == 0 \
		&& list->flag_p == -1)
		ft_printf_hexa_width(list, str);
	else if (list->flag_w > 0 && list->flag_m == 1 && list->flag_p == -1)
		ft_printf_hexa_minus(list, str);
	else if (list->flag_w > 0 && list->flag_z == 1 && list->flag_p == -1)
		ft_printf_hexa_zero(list, str);
	else if (list->flag_w == 0 && list->flag_m == 0 && list->flag_z == 0 \
		&& list->flag_p > -1)
		ft_printf_hexa_precision(list, str);
	else if (list->flag_w > 0 && list->flag_m == 0 && list->flag_z == 0 \
		&& list->flag_p > -1)
		ft_printf_hexa_w_p(list, str);
	else if (list->flag_w > 0 && list->flag_m == 1 && list->flag_p > -1)
		ft_printf_hexa_w_p_m(list, str);
	else if (list->flag_w > 0 && list->flag_p > -1 && list->flag_z == 1)
		ft_printf_hexa_w_p(list, str);
	else
		ft_printf_hexa_aux(list, str);
	free(str);
}
