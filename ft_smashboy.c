/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smashboy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 10:27:18 by poretha           #+#    #+#             */
/*   Updated: 2019/11/14 17:31:20 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_issmashboy(char *ptr)
{
	while (*ptr != '#')
		ptr++;
	if (ptr[0] == '#' && ptr[1] == '#' && ptr[5] == '#' && ptr[6] == '#' &&
		ptr[2] != '#' && ptr[4] != '#' && ptr[7] != '#')
		return (SMASHBOY);
	else
		return (0);
}

void		ft_setsmashboy(t_tetrino *ptr)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == 0 && (j == 0 || j == 1))
				ptr->hash[i][j] = ptr->c;
			else if (i == 1 && (j == 0 || j == 1))
				ptr->hash[i][j] = ptr->c;
			else
				ptr->hash[i][j] = '.';
			j++;
		}
		i++;
	}
}
