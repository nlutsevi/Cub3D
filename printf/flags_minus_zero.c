/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_minus_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 18:53:30 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/11/02 19:43:53 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		flags_minus_zero(t_struct *list)
{
	while ((list->str[list->i] == '-') || (list->str[list->i] == '0'))
	{
		if (list->str[list->i] == '-')
		{
			list->flag_m = 1;
			list->flag_z = 0;
		}
		if ((list->str[list->i] == '0') && (list->flag_m == 0))
			list->flag_z = 1;
		list->i++;
	}
}
