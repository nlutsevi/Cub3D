/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 18:47:23 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/11/05 17:56:23 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_s_aux(t_struct *list, char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		list->ret += write(1, &s[i], 1);
		i++;
	}
}

void	ft_printf_s(t_struct *list, char *s)
{
	if (s == NULL)
		s = "(null)";
	if (list->flag_w > 0 && list->flag_m == 0 && list->flag_z == 0 \
		&& list->flag_p <= -1)
		ft_printf_s_width(list, s);
	else if (list->flag_w > 0 && list->flag_m == 1 && list->flag_p <= -1)
		ft_printf_s_minus(list, s);
	else if (list->flag_w >= 0 && list->flag_z == 1 && list->flag_p == -1)
		ft_printf_s_zero(list, s);
	else if (list->flag_p > -1 && list->flag_m == 0 && list->flag_z == 0 \
		&& list->flag_w == 0)
		ft_printf_s_precision(list, s);
	else if (list->flag_w > 0 && list->flag_m == 0 && list->flag_z == 0 \
		&& list->flag_p > -1)
		ft_printf_s_w_p(list, s);
	else if (list->flag_w >= 0 && list->flag_m == 1 && list->flag_p > -1)
		ft_printf_s_m_w_p(list, s);
	else
		ft_printf_s_aux(list, s);
}

void	ft_printf_s_width(t_struct *list, char *s)
{
	int		i;
	size_t	w;

	i = 0;
	w = list->flag_w;
	while (w > ft_strlen(s))
	{
		list->ret += write(1, " ", 1);
		w--;
	}
	while (s[i] != '\0')
	{
		list->ret += write(1, &s[i], 1);
		i++;
	}
}

void	ft_printf_s_minus(t_struct *list, char *s)
{
	size_t	i;
	size_t	w;

	i = 0;
	w = list->flag_w;
	while (s[i] != '\0')
	{
		list->ret += write(1, &s[i], 1);
		i++;
	}
	while (i < w)
	{
		list->ret += write(1, " ", 1);
		i++;
	}
}

void	ft_printf_s_precision(t_struct *list, char *s)
{
	int		i;
	size_t	p;

	i = 0;
	p = list->flag_p;
	if (p < ft_strlen(s))
	{
		while (p > 0)
		{
			list->ret += write(1, &s[i], 1);
			p--;
			i++;
		}
	}
	else if (p >= ft_strlen(s))
	{
		while (s[i] != '\0')
		{
			list->ret += write(1, &s[i], 1);
			i++;
		}
	}
}
