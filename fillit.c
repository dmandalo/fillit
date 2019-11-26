/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:11:55 by poretha           #+#    #+#             */
/*   Updated: 2019/11/13 20:16:12 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				main(int ac, char **av)
{
	t_tetrino	**tetriminos;
	t_square	*sq;

	if (ac != 2)
	{
		ft_putendl("usage: fillit source_file");
		return (0);
	}
	tetriminos = ft_tetread(open(av[1], O_RDONLY));
	if (!tetriminos)
		return (0);
	sq = ft_solve_tet(tetriminos);
	ft_print_square(sq);
	ft_free_square(sq);
	ft_freetetrinos(tetriminos);
	return (0);
}
