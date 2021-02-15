/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:53:04 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/11/07 20:34:49 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	list_init(t_struct *list)
{
	list->flag_m = 0;
	list->flag_z = 0;
	list->flag_w = 0;
	list->flag_p = -1;
	list->ret = 0;
	list->i = 0;
}

void	seek_flags(t_struct *list)
{
	if ((list->str[list->i] == '-') || (list->str[list->i] == '0'))
		flags_minus_zero(list);
	if ((list->str[list->i] == '*') || (ft_isdigit(list->str[list->i]) == 1))
		flag_width(list);
	if (list->str[list->i] == '.')
		flag_precision(list);
}

void	ft_parser_aux(t_struct *list)
{
	if (list->str[list->i] == 'c')
		ft_printf_c(list, va_arg(list->args, int));
	else if (list->str[list->i] == 's')
		ft_printf_s(list, va_arg(list->args, char*));
	else if (list->str[list->i] == 'd' || list->str[list->i] == 'i')
		ft_printf_d_i(list, va_arg(list->args, int));
	else if (list->str[list->i] == 'u')
		ft_printf_u(list, va_arg(list->args, unsigned int));
	else if (list->str[list->i] == '%')
		ft_printf_percent(list, 37);
	else if (list->str[list->i] == 'p')
		ft_printf_pointer(list, va_arg(list->args, unsigned long));
	else if (list->str[list->i] == 'x')
		ft_printf_hexa(list, va_arg(list->args, unsigned int));
	else if (list->str[list->i] == 'X')
		ft_printf_hexa_upper(list, va_arg(list->args, unsigned int));
	else
	{
		write(1, "", 1);
		if (list->str[list->i] != '\0')
			list->i++;
	}
}

void	ft_parser(t_struct *list)
{
	while (list->str[list->i] != '\0')
	{
		if (list->str[list->i] == '%')
		{
			list->i++;
			seek_flags(list);
			ft_parser_aux(list);
			if (list->str[list->i] != '\0')
				list->i++;
		}
		else
		{
			list->ret += write(1, &list->str[list->i], 1);
			list->i++;
		}
	}
}

int		ft_printf(const char *format, ...)
{
	t_struct	list;

	list.str = (char*)format;
	list_init(&list);
	va_start(list.args, format);
	ft_parser(&list);
	va_end(list.args);
	return (list.ret);
}
