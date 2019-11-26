/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:45:37 by poretha           #+#    #+#             */
/*   Updated: 2019/11/14 19:58:35 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define HERO_H 1
# define HERO_V 2
# define SMASHBOY 3
# define TEEWEE_0 4
# define TEEWEE_1 5
# define TEEWEE_2 6
# define TEEWEE_3 7
# define ORANGE_RICKY_0 8
# define ORANGE_RICKY_1 9
# define ORANGE_RICKY_2 10
# define ORANGE_RICKY_3 11
# define BLUE_RICKY_0 12
# define BLUE_RICKY_1 13
# define BLUE_RICKY_2 14
# define BLUE_RICKY_3 15
# define CLEVELAND_Z0 16
# define CLEVELAND_Z1 17
# define RHODE_ISLAND_Z0 18
# define RHODE_ISLAND_Z1 19
# define BUFF_SIZE 21
# define HASH_SIZE 4

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_tetrino
{
	char			c;
	int				hash[HASH_SIZE][HASH_SIZE];
	int				type;
	int				height;
	int				width;
}					t_tetrino;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_square
{
	char			**square;
	int				size;
}					t_square;

t_tetrino			**ft_tetread(int fd);
int					ft_ishero(char *ptr);
int					ft_issmashboy(char *ptr);
int					ft_isteewee(char *ptr);
int					ft_isoricky(char *ptr);
int					ft_isbricky(char *ptr);
int					ft_isszshape(char *ptr);
int					ft_gettypetet(char *ptr);
int					ft_gettet(char *ptr);
t_tetrino			**ft_tetfree(char *tetriminos);
int					ft_istetrino(char *ptr);
void				ft_setshapes(t_tetrino *ptr);
void				ft_sethero(t_tetrino *ptr);
void				ft_setsmashboy(t_tetrino *ptr);
void				ft_setteewee(t_tetrino *ptr);
void				ft_setszshape(t_tetrino *ptr);
void				ft_setoricky(t_tetrino *ptr);
void				ft_setbricky(t_tetrino *ptr);
int					ft_getsizemap(t_tetrino **ptr);
void				ft_free_square(t_square *sq);
t_tetrino			**ft_tetreaderror(void);
t_square			*ft_error_square(t_square *sq);
int					ft_tetheight(int t);
int					ft_tetwidth(int t);
t_square			*ft_new_square(int size);
t_square			*ft_solve_tet(t_tetrino **tetriminos);
void				ft_print_square(t_square *sq);
void				ft_freetetrinos(t_tetrino **tet);

#endif
