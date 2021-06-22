# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: milmi <milmi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/10 00:43:14 by milmi             #+#    #+#              #
#    Updated: 2021/06/07 16:59:48 by milmi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
SRCS = operators.c push_swap.c solve_less_5.c solve_less_100.c solver.c utils.c solve_less_100_norm.c

FLAGS= -Wall -Wextra -Werror
rm = rm -f
CC = gcc

all : $(NAME)

$(NAME) : LIBFT
	@cp ./libft/libft.a .
	@$(CC) $(FLAGS) $(SRCS) libft.a -o $(NAME)
	
LIBFT :
	@$(MAKE) -C ./libft
	
clean :
	@$(rm) libft.a
	@$(MAKE) -C ./libft clean
	
fclean : clean
	@$(rm) $(NAME)
	@$(MAKE) -C ./libft fclean

re: fclean all