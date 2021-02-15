/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_h_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 20:07:32 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/11/06 19:00:38 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_hexa_width(t_struct *list, char *str)
{
	size_t	w;
	size_t	i;

	i = 0;
	w = list->flag_w;
	while (w > ft_strlen(str))
	{
		list->ret += write(1, " ", 1);
		w--;
	}
	while (str[i] != '\0')
	{
		list->ret += write(1, &str[i], 1);
		i++;
	}
}

void	ft_printf_hexa_minus(t_struct *list, char *str)
{
	size_t	i;
	size_t	w;

	i = 0;
	w = list->flag_w;
	if (w > ft_strlen(str))
	{
		while (str[i] != '\0')
		{
			list->ret += write(1, &str[i], 1);
			i++;
			w--;
		}
		while (w-- > 0)
			list->ret += write(1, " ", 1);
	}
	else
	{
		while (str[i] != '\0')
		{
			list->ret += write(1, &str[i], 1);
			i++;
		}
	}
}

void	ft_printf_hexa_zero(t_struct *list, char *str)
{
	size_t	i;
	size_t	w;

	i = 0;
	w = list->flag_w;
	while (w > ft_strlen(str))
	{
		list->ret += write(1, "0", 1);
		w--;
	}
	while (str[i] != '\0')
	{
		list->ret += write(1, &str[i], 1);
		i++;
	}
}

void	ft_printf_hexa_precision(t_struct *list, char *str)
{
	int		i;
	size_t	p;

	i = 0;
	p = list->flag_p;
	while (p > ft_strlen(str))
	{
		list->ret += write(1, "0", 1);
		p--;
	}
	if (list->flag_p > 0)
	{
		while (str[i] != '\0')
		{
			list->ret += write(1, &str[i], 1);
			i++;
		}
	}
}
