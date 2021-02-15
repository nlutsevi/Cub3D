/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_h.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:01:18 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/11/09 17:46:52 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_lowercase(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
			i++;
		}
		else
			i++;
	}
	return (str);
}

char	*ft_printf_hexa_aux2(unsigned int h)
{
	char	*str;
	long	value;

	value = (long)h;
	str = ft_itoa_base(value, 16);
	str = ft_lowercase(str);
	return (str);
}

void	ft_printf_hexa(t_struct *list, unsigned int h)
{
	char	*str;

	str = ft_printf_hexa_aux2(h);
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
