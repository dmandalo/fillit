/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setshapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 10:27:18 by poretha           #+#    #+#             */
/*   Updated: 2019/11/14 17:27:58 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_setshapes(t_tetrino *ptr)
{
	if (ptr->type == HERO_H || ptr->type == HERO_V)
		ft_sethero(ptr);
	else if (ptr->type == SMASHBOY)
		ft_setsmashboy(ptr);
	else if (ptr->type == TEEWEE_0 || ptr->type == TEEWEE_1 ||
		ptr->type == TEEWEE_2 || ptr->type == TEEWEE_3)
		ft_setteewee(ptr);
	else if (ptr->type == ORANGE_RICKY_0 || ptr->type == ORANGE_RICKY_1 ||
		ptr->type == ORANGE_RICKY_2 || ptr->type == ORANGE_RICKY_3)
		ft_setoricky(ptr);
	else if (ptr->type == BLUE_RICKY_0 || ptr->type == BLUE_RICKY_1 ||
		ptr->type == BLUE_RICKY_2 || ptr->type == BLUE_RICKY_3)
		ft_setbricky(ptr);
	else if (ptr->type == CLEVELAND_Z0 || ptr->type == CLEVELAND_Z1 ||
		ptr->type == RHODE_ISLAND_Z0 || ptr->type == RHODE_ISLAND_Z1)
		ft_setszshape(ptr);
}
