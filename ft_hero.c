/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 10:27:18 by poretha           #+#    #+#             */
/*   Updated: 2019/11/14 17:22:29 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_ishero(char *ptr)
{
	while (*ptr != '#')
		ptr++;
	if (ptr[0] == '#' && ptr[1] == '#' && ptr[2] == '#' && ptr[3] == '#')
		return (HERO_H);
	else if (ptr[0] == '#' && ptr[5] == '#' && ptr[10] == '#' &&
		ptr[15] == '#' && ptr[1] != '#' && ptr[4] != '#' &&
		ptr[6] != '#' && ptr[9] != '#' && ptr[11] != '#' &&
		ptr[14] != '#' && ptr[16] != '#')
		return (HERO_V);
	else
		return (0);
}

void		ft_sethero(t_tetrino *ptr)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (ptr->type == HERO_H && i == 0)
				ptr->hash[i][j] = ptr->c;
			else if (ptr->type == HERO_V && j == 0)
				ptr->hash[i][j] = ptr->c;
			else
				ptr->hash[i][j] = '.';
			j++;
		}
		i++;
	}
}
