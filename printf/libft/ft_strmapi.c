/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 18:15:03 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/07/09 14:29:36 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*out_str;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	if (!(out_str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		out_str[i] = f(i, s[i]);
		i++;
	}
	out_str[i] = 0;
	return (out_str);
}
