# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grougeau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/22 11:10:35 by grougeau          #+#    #+#              #
#    Updated: 2019/05/22 11:33:14 by grougeau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIBRARY = libft/libft.a

SRC = main.c \
	solver.c \
	define_boardsize.c \
	check_multiple_tetrimino.c \
	coordinates_tetrimino.c \
	fill_board.c \
	open_store_tetrimino.c

BINARY = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -Iincludes.
CC = gcc

all: $(NAME)

$(NAME): $(LIBRARY)
	$(CC) $(FLAGS) -g -c $(SRC)
	$(CC) $(FLAGS) -g  -o  $(NAME) $(BINARY) libft/libft.a
	
$(LIBRARY):
	make -C libft/
	
clean:
	rm -f $(BINARY)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: clean fclean re all
