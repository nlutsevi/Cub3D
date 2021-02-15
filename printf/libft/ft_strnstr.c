/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 18:16:43 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/07/09 14:29:43 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *haystack, \
				const char *needle, size_t len)
{
	char	*h;
	size_t	needle_len;
	size_t	i;
	size_t	j;

	h = (char *)haystack;
	if (!(needle_len = ft_strlen(needle)))
		return (h);
	if (ft_strlen(haystack) < needle_len || len < needle_len)
		return (NULL);
	i = 0;
	while (h[i] && i <= len - needle_len)
	{
		j = 0;
		while (needle[j] && needle[j] == h[i + j])
			j++;
		if (j == needle_len)
			return (&h[i]);
		i++;
	}
	return (NULL);
}
