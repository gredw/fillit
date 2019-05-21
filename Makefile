NAME = fillit

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

$(NAME):
	$(CC) $(FLAGS) -g -c $(SRC)
	$(CC) $(FLAGS) -g  -o  $(NAME) $(BINARY)
	
	
clean:
	/bin/rm -f $(BINARY)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
