/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 18:09:57 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/07/09 14:29:04 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strchr(const char *s, int c)
{
	char *ptr;
	char sym;

	ptr = (char *)s;
	sym = (char)c;
	if (sym == '\0')
		return (ptr + ft_strlen(s));
	while (*ptr)
	{
		if (*ptr == sym)
			return (ptr);
		ptr++;
	}
	return (NULL);
}
