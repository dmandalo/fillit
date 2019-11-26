/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poretha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:23:57 by poretha           #+#    #+#             */
/*   Updated: 2019/09/18 08:09:41 by poretha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstprev(t_list *head, t_list *cur)
{
	t_list	*prev;

	if (!head || !cur || head == cur)
		return (NULL);
	prev = head;
	while (prev->next != cur)
		prev = prev->next;
	return (prev);
}
