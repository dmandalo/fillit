/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 09:52:25 by poretha           #+#    #+#             */
/*   Updated: 2019/11/18 15:46:57 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_square(t_square *sq)
{
	int i;
	int j;

	i = 0;
	while (i < sq->size)
	{
		j = 0;
		while (j < sq->size)
			ft_putchar(sq->square[i][j++]);
		if (i < sq->size)
			ft_putchar('\n');
		i++;
	}
}
