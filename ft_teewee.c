/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_teewee.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 10:27:18 by poretha           #+#    #+#             */
/*   Updated: 2019/11/14 17:30:26 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_isteewee(char *ptr)
{
	while (*ptr != '#')
		ptr++;
	if (ptr[0] == '#' && ptr[4] == '#' && ptr[5] == '#' && ptr[6] == '#' &&
		ptr[1] != '#' && ptr[3] != '#' && ptr[7] != '#')
		return (TEEWEE_0);
	else if (ptr[0] == '#' && ptr[5] == '#' && ptr[6] == '#' &&
		ptr[10] == '#' && ptr[1] != '#' && ptr[4] != '#' &&
		ptr[7] != '#' && ptr[9] != '#' && ptr[11] != '#')
		return (TEEWEE_1);
	else if (ptr[0] == '#' && ptr[1] == '#' && ptr[2] == '#' &&
		ptr[6] == '#' && ptr[3] != '#' && ptr[5] != '#' && ptr[7] != '#')
		return (TEEWEE_2);
	else if (ptr[0] == '#' && ptr[4] == '#' && ptr[5] == '#' &&
		ptr[10] == '#' && ptr[1] != '#' && ptr[3] != '#' &&
		ptr[6] != '#' && ptr[9] != '#' && ptr[11] != '#')
		return (TEEWEE_3);
	else
		return (0);
}

void		ft_setteewee(t_tetrino *ptr)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			if ((i == 1 && j == 1) ||
				(ptr->type == TEEWEE_0 && i == 1 && j == 2) ||
				(ptr->type == TEEWEE_1 && i == 2 && j == 0) ||
				(ptr->type == TEEWEE_2 && i == 0 && j == 2) ||
				(ptr->type == TEEWEE_3 && i == 2 && j == 1) ||
				(i == 0 && j == 1 && (ptr->type == TEEWEE_0 ||
				ptr->type == TEEWEE_2 || ptr->type == TEEWEE_3)) ||
				(i == 1 && j == 0 && (ptr->type == TEEWEE_0 ||
				ptr->type == TEEWEE_1 || ptr->type == TEEWEE_3)) ||
				(i == 0 && j == 0 && (ptr->type == TEEWEE_1 ||
				ptr->type == TEEWEE_2)))
				ptr->hash[i][j++] = ptr->c;
			else
				ptr->hash[i][j++] = '.';
		i++;
	}
}
