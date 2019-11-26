/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poretha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 10:03:56 by poretha           #+#    #+#             */
/*   Updated: 2019/09/16 08:30:03 by poretha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert(t_list *alst, t_list *newlst)
{
	t_list	*temp;

	if (!newlst || !alst)
		return ;
	temp = alst->next;
	alst->next = newlst;
	newlst->next = temp;
}
