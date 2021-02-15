/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:07:54 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/11/07 20:32:12 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_p_width(t_struct *list, char *str)
{
	int		i;
	size_t	w;

	i = 0;
	w = list->flag_w;
	while (w > (ft_strlen(str) + 2))
	{
		list->ret += write(1, " ", 1);
		w--;
	}
	list->ret += write(1, "0", 1);
	list->ret += write(1, "x", 1);
	while (str[i] != '\0')
	{
		list->ret += write(1, &str[i], 1);
		i++;
	}
}

void	ft_printf_p_minus(t_struct *list, char *str)
{
	int		i;
	int		w;

	i = 0;
	w = list->flag_w;
	list->ret += write(1, "0", 1);
	list->ret += write(1, "x", 1);
	while (str[i] != '\0')
	{
		list->ret += write(1, &str[i], 1);
		i++;
		w--;
	}
	while (w > 2)
	{
		list->ret += write(1, " ", 1);
		w--;
	}
}

void	ft_printf_p_prec(t_struct *list, char *str)
{
	int		i;
	size_t	p;

	i = 0;
	p = list->flag_p;
	list->ret += write(1, "0", 1);
	list->ret += write(1, "x", 1);
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

void	ft_printf_p_w_p_aux(t_struct *list, char *str, size_t w, size_t p)
{
	int		i;

	i = 0;
	if (list->flag_p == 0)
		str = "";
	if (p > ft_strlen(str))
	{
		while (w-- > (p + 2))
			list->ret += write(1, " ", 1);
	}
	else if (p <= ft_strlen(str))
	{
		while (w-- > (ft_strlen(str) + 2))
			list->ret += write(1, " ", 1);
	}
	list->ret += write(1, "0", 1);
	list->ret += write(1, "x", 1);
	w -= 1;
	while (w-- > ft_strlen(str))
		list->ret += write(1, "0", 1);
	while (str[i] != '\0')
	{
		list->ret += write(1, &str[i], 1);
		i++;
	}
}

void	ft_printf_p_w_p(t_struct *list, char *str)
{
	int		i;
	size_t	w;
	size_t	p;

	i = 0;
	w = list->flag_w;
	p = list->flag_p;
	if (list->flag_w >= list->flag_p)
		ft_printf_p_w_p_aux(list, str, w, p);
	else if (list->flag_w < list->flag_p)
	{
		list->ret += write(1, "0", 1);
		list->ret += write(1, "x", 1);
		while (p > ft_strlen(str))
		{
			list->ret += write(1, "0", 1);
			p--;
		}
		while (str[i] != '\0')
		{
			list->ret += write(1, &str[i], 1);
			i++;
		}
	}
}
