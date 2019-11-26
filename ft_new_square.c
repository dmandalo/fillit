/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:18:34 by poretha           #+#    #+#             */
/*   Updated: 2019/11/14 19:12:42 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_square	*ft_new_square(int size)
{
	t_square	*sq;
	int			i;
	int			j;

	i = 0;
	if ((sq = (t_square *)ft_memalloc(sizeof(t_square))) == NULL)
		return (ft_error_square(sq));
	if ((sq->square = (char **)ft_memalloc(sizeof(char *) * size)) == NULL)
		return (ft_error_square(sq));
	while (i < size)
	{
		if ((sq->square[i] = (char *)ft_memalloc(sizeof(char) * size)) == NULL)
			return (ft_error_square(sq));
		i++;
	}
	sq->size = size;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			sq->square[i][j++] = '.';
		i++;
	}
	return (sq);
}
