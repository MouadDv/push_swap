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
LIBFT = libft.a
CHECKER = checker
BNS_NAME = checker
SRCS = operators.c operators2.c push_swap.c solve_less_5.c solve_less_100.c solver.c utils.c utils2.c solve_less_100_norm.c
BNS = checker.c checker_operators.c checker_operators2.c solve_less_100.c solve_less_100_norm.c utils.c utils2.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c get_next_line/get_next_line_norm.c
FLAGS= -Wall -Wextra -Werror -fsanitize=address
rm = rm -f
CC = gcc

all : $(NAME)

$(NAME) : $(LIBFT)
	$(CC) $(FLAGS) $(SRCS) $(LIBFT) -o $(NAME)

bonus : $(LIBFT) $(CHECKER)

$(CHECKER) :
	$(CC) $(FLAGS) $(BNS) $(LIBFT) -o $(BNS_NAME)
	
$(LIBFT) :
	@$(MAKE) -C ./libft
	@cp ./libft/libft.a .

both: all bonus

clean :
	@$(MAKE) -C ./libft clean
	
fclean : clean
	@$(rm) $(NAME)
	@$(rm) $(BNS_NAME)
	@$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all bonus both clean fclean re