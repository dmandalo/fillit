/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:18:34 by poretha           #+#    #+#             */
/*   Updated: 2019/11/14 18:05:06 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_freetetrinos(t_tetrino **tet)
{
	int	i;

	i = 0;
	while (tet[i])
	{
		free(tet[i]);
		i++;
	}
	free(tet);
}

t_tetrino	**ft_tetfree(char *tetriminos)
{
	free(tetriminos);
	ft_putendl("error");
	return (NULL);
}

t_tetrino	**ft_tetreaderror(void)
{
	ft_putendl("error");
	return (NULL);
}

t_square	*ft_error_square(t_square *sq)
{
	int	i;

	i = 0;
	if (sq)
	{
		if (!sq->square)
			free(sq);
		else
		{
			while (sq->square[i])
				free(sq->square[i++]);
			free(sq->square);
			free(sq);
		}
	}
	ft_putendl("error");
	return (NULL);
}

void		ft_free_square(t_square *sq)
{
	int	i;

	i = 0;
	while (i < sq->size)
		free(sq->square[i++]);
	free(sq->square);
	free(sq);
}
