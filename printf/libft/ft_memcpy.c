/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 18:06:34 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/07/10 17:32:58 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (n == 0 || dst == src)
		return (dst);
	d = (char*)dst;
	s = (char*)src;
	while (--n)
		*d++ = *s++;
	*d = *s;
	return (dst);
}
