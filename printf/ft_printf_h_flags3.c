/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_h_flags3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 20:34:08 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/11/05 17:47:08 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_hexa_w_p_m_aux(t_struct *list, char *str, size_t w, size_t p)
{
	int		i;

	i = 0;
	while (p > ft_strlen(str))
	{
		list->ret += write(1, "0", 1);
		p--;
		w--;
	}
	while (str[i] != '\0')
	{
		list->ret += write(1, &str[i], 1);
		i++;
		w--;
	}
	while (w > 0)
	{
		list->ret += write(1, " ", 1);
		w--;
	}
}

void	ft_printf_hexa_w_p_m_aux2(t_struct *list, char *str, size_t w)
{
	int		i;

	i = 0;
	if (list->flag_p > 0)
	{
		while (str[i] != '\0')
		{
			list->ret += write(1, &str[i], 1);
			i++;
			w--;
		}
	}
	else if (list->flag_p == 0)
	{
		list->ret += write(1, " ", 1);
		w--;
	}
	while (w > 0)
	{
		list->ret += write(1, " ", 1);
		w--;
	}
}

void	ft_printf_hexa_w_p_m(t_struct *list, char *str)
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
	{
		if (p >= ft_strlen(str))
			ft_printf_hexa_w_p_m_aux(list, str, w, p);
		else if (p < ft_strlen(str))
			ft_printf_hexa_w_p_m_aux2(list, str, w);
	}
}
