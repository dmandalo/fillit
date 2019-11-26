/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ricky.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 10:27:18 by poretha           #+#    #+#             */
/*   Updated: 2019/11/14 17:27:08 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_isoricky(char *ptr)
{
	while (*ptr != '#')
		ptr++;
	if (ptr[0] == '#' && ptr[3] == '#' && ptr[4] == '#' && ptr[5] == '#' &&
		ptr[1] != '#' && ptr[2] != '#' && ptr[6] != '#')
		return (ORANGE_RICKY_0);
	else if (ptr[0] == '#' && ptr[5] == '#' && ptr[10] == '#' &&
		ptr[11] == '#' && ptr[1] != '#' && ptr[4] != '#' &&
		ptr[6] != '#' && ptr[9] != '#' && ptr[12] != '#')
		return (ORANGE_RICKY_1);
	else if (ptr[0] == '#' && ptr[1] == '#' && ptr[2] == '#' &&
		ptr[5] == '#' && ptr[3] != '#' && ptr[4] != '#' && ptr[6] != '#')
		return (ORANGE_RICKY_2);
	else if (ptr[0] == '#' && ptr[1] == '#' && ptr[6] == '#' &&
		ptr[11] == '#' && ptr[2] != '#' && ptr[5] != '#' &&
		ptr[7] != '#' && ptr[10] != '#' && ptr[12] != '#')
		return (ORANGE_RICKY_3);
	else
		return (0);
}

int		ft_isbricky(char *ptr)
{
	while (*ptr != '#')
		ptr++;
	if (ptr[0] == '#' && ptr[5] == '#' && ptr[6] == '#' && ptr[7] == '#' &&
		ptr[1] != '#' && ptr[4] != '#' && ptr[8] != '#')
		return (BLUE_RICKY_0);
	else if (ptr[0] == '#' && ptr[1] == '#' && ptr[5] == '#' &&
		ptr[10] == '#' && ptr[2] != '#' && ptr[4] != '#' && ptr[6] != '#' &&
		ptr[9] != '#' && ptr[11] != '#')
		return (BLUE_RICKY_1);
	else if (ptr[0] == '#' && ptr[1] == '#' && ptr[2] == '#' && ptr[7] == '#' &&
		ptr[3] != '#' && ptr[6] != '#' && ptr[8] != '#')
		return (BLUE_RICKY_2);
	else if (ptr[0] == '#' && ptr[5] == '#' && ptr[9] == '#' &&
			ptr[10] == '#' && ptr[1] != '#' && ptr[4] != '#' &&
			ptr[6] != '#' && ptr[8] != '#' && ptr[11] != '#')
		return (BLUE_RICKY_3);
	else
		return (0);
}

void	ft_setoricky(t_tetrino *ptr)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if ((ptr->type == ORANGE_RICKY_0 && ((i == 0 && j == 2) ||
				(i == 1 && (j == 0 || j == 1 || j == 2)))) ||
				(ptr->type == ORANGE_RICKY_1 && ((i == 2 && j == 1) ||
				(j == 0 && (i == 0 || i == 1 || i == 2)))) ||
				(ptr->type == ORANGE_RICKY_2 && ((i == 1 && j == 0) ||
				(i == 0 && (j == 0 || j == 1 || j == 2)))) ||
				(ptr->type == ORANGE_RICKY_3 && ((i == 0 && j == 0) ||
				(j == 1 && (i == 0 || i == 1 || i == 2)))))
				ptr->hash[i][j] = ptr->c;
			else
				ptr->hash[i][j] = '.';
			j++;
		}
		i++;
	}
}

void	ft_setbricky(t_tetrino *ptr)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if ((ptr->type == BLUE_RICKY_0 && ((i == 0 && j == 0) ||
				(i == 1 && (j == 0 || j == 1 || j == 2)))) ||
				(ptr->type == BLUE_RICKY_1 && ((i == 0 && j == 1) ||
				(j == 0 && (i == 0 || i == 1 || i == 2)))) ||
				(ptr->type == BLUE_RICKY_2 && ((i == 1 && j == 2) ||
				(i == 0 && (j == 0 || j == 1 || j == 2)))) ||
				(ptr->type == BLUE_RICKY_3 && ((i == 2 && j == 0) ||
				(j == 1 && (i == 0 || i == 1 || i == 2)))))
				ptr->hash[i][j] = ptr->c;
			else
				ptr->hash[i][j] = '.';
			j++;
		}
		i++;
	}
}
