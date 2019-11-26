/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poretha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 10:03:56 by poretha           #+#    #+#             */
/*   Updated: 2019/09/18 08:18:11 by poretha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstswap2(t_list *lst1, t_list *lst2, t_list *head)
{
	t_list	*prev1;
	t_list	*prev2;
	t_list	*next1;
	t_list	*next2;

	prev1 = ft_lstprev(head, lst1);
	prev2 = ft_lstprev(head, lst2);
	next1 = lst1->next;
	next2 = lst2->next;
	lst1->next = next2;
	lst2->next = next1;
	if (lst1 == next2 && lst2 != head)
		prev2->next = lst1;
	else if (lst2 == next1 && lst2 != head)
		prev1->next = lst2;
}

static void	ft_lstswap3(t_list *lst1, t_list *lst2, t_list *head)
{
	t_list	*prev1;
	t_list	*prev2;
	t_list	*next1;
	t_list	*next2;

	prev1 = ft_lstprev(head, lst1);
	prev2 = ft_lstprev(head, lst2);
	next1 = lst1->next;
	next2 = lst2->next;
	if (lst1 != head)
		prev1->next = lst2;
	lst2->next = next1;
	if (lst2 != head)
		prev2->next = lst1;
	lst1->next = next2;
}

void		ft_lstswap(t_list *lst1, t_list *lst2, t_list *head)
{
	if (!lst1 || !lst2 || !head)
		return ;
	if (lst1 == lst2->next || lst2 == lst1->next)
		ft_lstswap2(lst1, lst2, head);
	else
		ft_lstswap3(lst1, lst2, head);
}
