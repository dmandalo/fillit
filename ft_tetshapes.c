/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetshapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 10:27:18 by poretha           #+#    #+#             */
/*   Updated: 2019/11/13 20:34:49 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_tetheight(int t)
{
	if (t == HERO_H)
		return (1);
	else if (t == HERO_V)
		return (4);
	else if (t == SMASHBOY || t == TEEWEE_0 || t == TEEWEE_2 ||
			t == ORANGE_RICKY_0 || t == ORANGE_RICKY_2 ||
			t == BLUE_RICKY_0 || t == BLUE_RICKY_2 ||
			t == CLEVELAND_Z0 || t == RHODE_ISLAND_Z0)
		return (2);
	else
		return (3);
}

int			ft_tetwidth(int t)
{
	if (t == HERO_H)
		return (4);
	else if (t == HERO_V)
		return (1);
	else if (t == TEEWEE_0 || t == TEEWEE_2 ||
			t == ORANGE_RICKY_0 || t == ORANGE_RICKY_2 ||
			t == BLUE_RICKY_0 || t == BLUE_RICKY_2 ||
			t == CLEVELAND_Z0 || t == RHODE_ISLAND_Z0)
		return (3);
	else
		return (2);
}

int			ft_gettypetet(char *ptr)
{
	if (ft_ishero(ptr))
		return (1);
	else if (ft_issmashboy(ptr))
		return (2);
	else if (ft_isteewee(ptr))
		return (3);
	else if (ft_isoricky(ptr) || ft_isbricky(ptr))
		return (4);
	else if (ft_isszshape(ptr))
		return (5);
	return (0);
}

int			ft_gettet(char *ptr)
{
	int		nt;

	if (ft_istetrino(ptr) == 0)
		return (0);
	if ((nt = ft_ishero(ptr)) > 0)
		return (nt);
	else if ((nt = ft_issmashboy(ptr)) > 0)
		return (nt);
	else if ((nt = ft_isteewee(ptr)) > 0)
		return (nt);
	else if ((nt = ft_isoricky(ptr)) > 0)
		return (nt);
	else if ((nt = ft_isbricky(ptr)) > 0)
		return (nt);
	else if ((nt = ft_isszshape(ptr)) > 0)
		return (nt);
	return (0);
}

int			ft_istetrino(char *ptr)
{
	int		i;
	int		j;
	int		k;
	int		len;

	i = 0;
	j = 0;
	k = 0;
	len = ft_strlen(ptr);
	while (j < 20)
	{
		if (ptr[j] == '#')
			k++;
		if (ptr[j] == '.')
			i++;
		if ((j + 1) % 5 == 0 && ptr[j + 1] == '\n')
			j++;
		j++;
	}
	if ((j < len && ptr[j - 1] != '\n') || k != 4 || i != 12)
		return (0);
	return (1);
}
