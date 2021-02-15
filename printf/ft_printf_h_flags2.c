/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_h_flags2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 20:09:21 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/11/05 17:35:01 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_hexa_w_p_aux2(t_struct *list, char *str)
{
	int		i;
	size_t	w;
	size_t	p;

	i = 0;
	w = list->flag_w;
	p = list->flag_p;
	while (w-- > p)
		list->ret += write(1, " ", 1);
	while (p-- > ft_strlen(str))
		list->ret += write(1, "0", 1);
	while (str[i] != '\0')
	{
		list->ret += write(1, &str[i], 1);
		i++;
	}
}

void	ft_printf_hexa_w_p_aux(t_struct *list, char *str)
{
	int		i;
	size_t	w;
	size_t	p;

	i = 0;
	w = list->flag_w;
	p = list->flag_p;
	if (p >= ft_strlen(str))
		ft_printf_hexa_w_p_aux2(list, str);
	else if (p < ft_strlen(str))
	{
		while (w-- > ft_strlen(str))
			list->ret += write(1, " ", 1);
		if (list->flag_p > 0)
		{
			while (str[i] != '\0')
			{
				list->ret += write(1, &str[i], 1);
				i++;
			}
		}
		else if (list->flag_p == 0)
			list->ret += write(1, " ", 1);
	}
}

void	ft_printf_hexa_w_p(t_struct *list, char *str)
{
	int		i;
	size_t	w;
	size_t	p;

	i = 0;
	w = list->flag_w;
	p = list->flag_p;
	if (w <= p)
	{
		while (p-- > ft_strlen(str))
			list->ret += write(1, "0", 1);
		while (str[i] != '\0')
		{
			list->ret += write(1, &str[i], 1);
			i++;
		}
	}
	else if (w > p)
		ft_printf_hexa_w_p_aux(list, str);
}
