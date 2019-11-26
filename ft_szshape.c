/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_szshape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 10:27:18 by poretha           #+#    #+#             */
/*   Updated: 2019/11/14 19:10:46 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_isszshape(char *ptr)
{
	while (*ptr != '#')
		ptr++;
	if (ptr[0] == '#' && ptr[1] == '#' && ptr[4] == '#' && ptr[5] == '#' &&
		ptr[2] != '#' && ptr[3] != '#' && ptr[6] != '#')
		return (CLEVELAND_Z0);
	else if (ptr[0] == '#' && ptr[5] == '#' && ptr[6] == '#' &&
		ptr[11] == '#' && ptr[1] != '#' && ptr[4] != '#' &&
		ptr[7] != '#' && ptr[9] != '#' && ptr[12] != '#')
		return (CLEVELAND_Z1);
	else if (ptr[0] == '#' && ptr[1] == '#' && ptr[6] == '#' && ptr[7] == '#' &&
		ptr[2] != '#' && ptr[5] != '#' && ptr[8] != '#')
		return (RHODE_ISLAND_Z0);
	else if (ptr[0] == '#' && ptr[4] == '#' && ptr[5] == '#' &&
		ptr[9] == '#' && ptr[1] != '#' && ptr[3] != '#' &&
		ptr[6] != '#' && ptr[8] != '#' && ptr[10] != '#')
		return (RHODE_ISLAND_Z1);
	else
		return (0);
}

void		ft_setszshape(t_tetrino *ptr)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			if ((i == 1 && j == 1) || (ptr->type == CLEVELAND_Z0 &&
				i == 0 && j == 2) || (ptr->type == CLEVELAND_Z1 &&
				i == 2 && j == 1) || (ptr->type == RHODE_ISLAND_Z0 &&
				i == 1 && j == 2) || (ptr->type == RHODE_ISLAND_Z1 &&
				i == 2 && j == 0) || (i == 0 && j == 1 &&
				(ptr->type == CLEVELAND_Z0 || ptr->type == RHODE_ISLAND_Z0 ||
				ptr->type == RHODE_ISLAND_Z1)) || (i == 1 && j == 0 &&
				(ptr->type == CLEVELAND_Z0 || ptr->type == CLEVELAND_Z1 ||
				ptr->type == RHODE_ISLAND_Z1)) || (i == 0 && j == 0 &&
				(ptr->type == CLEVELAND_Z1 || ptr->type == RHODE_ISLAND_Z0)))
				ptr->hash[i][j++] = ptr->c;
			else
				ptr->hash[i][j++] = '.';
		i++;
	}
}
