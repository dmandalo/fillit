/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_tet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:18:34 by poretha           #+#    #+#             */
/*   Updated: 2019/11/14 20:06:11 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		setplace(t_square *sq, t_tetrino *tet, t_point p, char ch)
{
	int			i;
	int			j;

	i = 0;
	while (i < tet->height)
	{
		j = 0;
		while (j < tet->width)
		{
			if (tet->hash[i][j] != '.')
				sq->square[i + p.y][j + p.x] = ch;
			j++;
		}
		i++;
	}
}

static int		testplace(t_square *sq, t_tetrino *tet, t_point p)
{
	int	i;
	int	j;

	i = 0;
	while (i < tet->height)
	{
		j = 0;
		while (j < tet->width)
		{
			if (sq->square[i + p.y][j + p.x] != '.' && tet->hash[i][j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	setplace(sq, tet, p, tet->c);
	return (1);
}

static int		solve_tet2(t_square *sq, t_tetrino **tetriminos, int cnttet)
{
	t_point		p;
	t_tetrino	*tet;

	p.y = 0;
	if (!tetriminos[cnttet])
		return (1);
	tet = tetriminos[cnttet];
	while (p.y < sq->size - tet->height + 1)
	{
		p.x = 0;
		while (p.x < sq->size - tet->width + 1)
		{
			if (testplace(sq, tet, p))
			{
				if (solve_tet2(sq, tetriminos, cnttet + 1))
					return (1);
				else
					setplace(sq, tet, p, '.');
			}
			p.x++;
		}
		p.y++;
	}
	return (0);
}

t_square		*ft_solve_tet(t_tetrino **tetriminos)
{
	t_square	*sq;
	int			size;

	size = ft_getsizemap(tetriminos);
	if ((sq = ft_new_square(size)) == NULL)
		return (NULL);
	while (!solve_tet2(sq, tetriminos, 0))
	{
		size++;
		ft_free_square(sq);
		if ((sq = ft_new_square(size)) == NULL)
			return (NULL);
	}
	return (sq);
}
