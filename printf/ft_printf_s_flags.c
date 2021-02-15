/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:14:13 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/11/05 18:02:22 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_s_w_p_aux(t_struct *list, char *s, size_t w, size_t p)
{
	int		i;

	i = 0;
	if (p < ft_strlen(s))
	{
		while (w-- > p)
			list->ret += write(1, " ", 1);
		while (p > 0)
		{
			list->ret += write(1, &s[i], 1);
			i++;
			p--;
		}
	}
	else if (p >= ft_strlen(s))
	{
		while (w > ft_strlen(s))
		{
			list->ret += write(1, " ", 1);
			w--;
		}
		ft_printf_s_w_p_aux3(list, s);
	}
}

void	ft_printf_s_w_p_aux2(t_struct *list, char *s, size_t w)
{
	if (w >= ft_strlen(s))
	{
		while (w > ft_strlen(s))
		{
			list->ret += write(1, " ", 1);
			w--;
		}
		ft_printf_s_w_p_aux3(list, s);
	}
	else if (w < ft_strlen(s))
		ft_printf_s_w_p_aux3(list, s);
}

void	ft_printf_s_w_p_aux3(t_struct *list, char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		list->ret += write(1, &s[i], 1);
		i++;
	}
}

void	ft_printf_s_w_p(t_struct *list, char *s)
{
	int		i;
	size_t	w;
	size_t	p;

	i = 0;
	w = list->flag_w;
	p = list->flag_p;
	if (w >= p)
		ft_printf_s_w_p_aux(list, s, w, p);
	else if (w < p)
		ft_printf_s_w_p_aux2(list, s, w);
}

void	ft_printf_s_zero(t_struct *list, char *s)
{
	int		i;
	size_t	w;

	i = 0;
	w = list->flag_w;
	if (w > ft_strlen(s))
	{
		while (w > ft_strlen(s))
		{
			list->ret += write(1, "0", 1);
			w--;
		}
	}
	if (w <= ft_strlen(s))
	{
		while (s[i])
		{
			list->ret += write(1, &s[i], 1);
			i++;
		}
	}
}
