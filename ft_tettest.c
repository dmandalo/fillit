/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tettest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:18:34 by poretha           #+#    #+#             */
/*   Updated: 2019/11/13 20:34:58 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_getsizetet(int nt)
{
	if (nt == 0)
		return (0);
	else if (nt == HERO_H || nt == HERO_V)
		return (4);
	else if (nt == SMASHBOY)
		return (2);
	else
		return (3);
}

static int		tetminsize(t_tetrino **ptr)
{
	int			i;
	int			cnt;
	int			tmp;

	i = 0;
	cnt = 0;
	while (ptr[i])
	{
		tmp = ft_getsizetet(ptr[i]->type);
		if (cnt < tmp)
			cnt = tmp;
		i++;
	}
	return (cnt);
}

int				ft_getsizemap(t_tetrino **ptr)
{
	int			i;
	int			cnt;
	int			tmp;

	i = 0;
	cnt = 0;
	while (ptr[i])
	{
		cnt++;
		i++;
	}
	cnt *= 4;
	i = 1;
	while (i * i < cnt)
		i++;
	tmp = tetminsize(ptr);
	if (i < tmp)
		return (tmp);
	else
		return (i);
}
