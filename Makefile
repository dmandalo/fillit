# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: poretha <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/18 08:25:27 by poretha           #+#    #+#              #
#    Updated: 2019/09/29 10:05:14 by poretha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = fillit.c ft_tetread.c ft_tettest.c ft_tetshapes.c ft_ricky.c ft_smashboy.c \
	ft_new_square.c ft_setshapes.c ft_memory.c ft_szshape.c ft_teewee.c \
	ft_solve_tet.c ft_print_square.c ft_hero.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

HEADER = -c -I fillit.h

all: $(NAME)

$(OBJ): %.o: %.c
		@gcc -c -Wall -Werror -Wextra -I libft/ $< -o $@

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJ)
	@gcc $(OBJ) $(LIBFT) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft fclean

re: fclean all
