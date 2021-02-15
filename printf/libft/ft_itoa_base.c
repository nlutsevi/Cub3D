/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 17:51:40 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/11/02 20:04:03 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numlen(long value, int base)
{
	int		size;

	size = 1;
	if (base != 10 && value < 0)
		value = -value;
	if (value < 0)
		size++;
	while (value / base)
	{
		size++;
		value /= base;
	}
	return (size);
}

char	*ft_revstr(char *str)
{
	int		length;
	int		i;
	char	tmp;

	length = 0;
	while (str[length])
		length++;
	i = 0;
	while (i < (length / 2))
	{
		tmp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = tmp;
		i++;
	}
	return (str);
}

int		ft_itoa_base_aux(int base, long value, int *sign)
{
	if (base < 2 || base > 16)
		return (0);
	if (value < 0)
		*sign = -1;
	else
		*sign = 1;
	return (*sign);
}

char	*ft_itoa_base(long value, int base)
{
	long	length;
	char	*result;
	int		sign;
	int		i;

	ft_itoa_base_aux(base, value, &sign);
	length = ft_numlen(value, base);
	if (!(result = (char*)malloc(sizeof(char) * (length + 2))))
		return (NULL);
	i = 0;
	while (i < length)
	{
		if (base <= 10 || (base > 10 && (value % base) < 10))
			result[i] = (value % base) + 48;
		else
			result[i] = (value % base) - 10 + 65;
		value /= base;
		i++;
	}
	if (sign < 0)
		result[i++] = '-';
	result[i] = '\0';
	return (ft_revstr(result));
}
