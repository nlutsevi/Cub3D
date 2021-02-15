/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:19:59 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/11/09 17:49:06 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_mempointer(unsigned long number)
{
	char *str;

	str = ft_itoa_base(number, 16);
	return (str);
}

void	ft_printf_pointer(t_struct *list, unsigned long number)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_mempointer(number);
	str = ft_lowercase(str);
	if (list->flag_w > 0 && list->flag_m == 0 && list->flag_z == 0 \
		&& list->flag_p == -1)
		ft_printf_p_width(list, str);
	else if (list->flag_w > 0 && list->flag_m == 1 && list->flag_p == -1)
		ft_printf_p_minus(list, str);
	else if (list->flag_w == 0 && list->flag_m == 0 && list->flag_z == 0 \
		&& list->flag_p > -1)
		ft_printf_p_prec(list, str);
	else if (list->flag_w > 0 && list->flag_m == 0 && list->flag_z == 0 \
		&& list->flag_p > -1)
		ft_printf_p_w_p(list, str);
	else
	{
		list->ret += write(1, "0", 1);
		list->ret += write(1, "x", 1);
		while (str[i] != '\0')
			list->ret += write(1, &str[i++], 1);
	}
	free(str);
}
