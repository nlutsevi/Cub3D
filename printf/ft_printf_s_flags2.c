/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s_flags2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:31:55 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/11/05 17:49:54 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_s_m_w_p_aux(t_struct *list, char *s, size_t w)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		list->ret += write(1, &s[i], 1);
		i++;
		w--;
	}
	while (w > 0)
	{
		list->ret += write(1, " ", 1);
		w--;
	}
}

void	ft_printf_s_m_w_p_aux2(t_struct *list, char *s, size_t w, size_t p)
{
	int		i;

	i = 0;
	while (p > 0)
	{
		list->ret += write(1, &s[i], 1);
		i++;
		p--;
		w--;
	}
	while (w > 0)
	{
		list->ret += write(1, " ", 1);
		w--;
	}
}

void	ft_printf_s_m_w_p_aux4(t_struct *list, char *s, size_t p)
{
	int		i;

	i = 0;
	while (p-- > 0)
	{
		list->ret += write(1, &s[i], 1);
		i++;
	}
}

void	ft_printf_s_m_w_p(t_struct *list, char *s)
{
	int		i;
	size_t	w;
	size_t	p;

	i = 0;
	w = list->flag_w;
	p = list->flag_p;
	if (w > p)
	{
		if (p >= ft_strlen(s))
			ft_printf_s_m_w_p_aux(list, s, w);
		else if (p < ft_strlen(s))
			ft_printf_s_m_w_p_aux2(list, s, w, p);
	}
	else if (w < p)
	{
		if (p >= ft_strlen(s))
			ft_printf_s_w_p_aux3(list, s);
		else if (p < ft_strlen(s))
			if (list->flag_p > 0)
				ft_printf_s_m_w_p_aux4(list, s, p);
	}
}
