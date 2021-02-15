/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 18:02:40 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/07/08 18:03:03 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ptr;
	unsigned char sym;

	ptr = (unsigned char*)s;
	sym = (unsigned char)c;
	while (n--)
	{
		if (*ptr != sym)
			ptr++;
		else
			return (ptr);
	}
	return (NULL);
}
