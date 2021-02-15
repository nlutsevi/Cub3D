/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:36:31 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/07/16 13:34:56 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	t_list	*current;

	if (!lst)
		return ;
	current = lst;
	while (current != NULL)
	{
		(*f)(current->content);
		current = current->next;
	}
}
