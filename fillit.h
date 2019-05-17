#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# define BUFF_SIZE 546

char	***malloc_3darray(int col, int row, int z);
int		open_check(char *filename, char *str);
char	***store_tretrimino(char *filename, int *ret);
int		count_hashtagdot (char **tab);
int		check_validchar(char **tab);
int		check_nbconnexions(char **tab);
int		check_tetrimino(char ***tab, int *ret);
char	**define_boardsize(int i);
int 	*coordinates(int nb, char ***tetriminos);
int 	board_width(int nb);
int		*get_board_coordinates(char **board, int width);
int		board_width_bis(char **board);
int 	fit_on_board(int pn, int *coord, int *xandy, char **board);
char 	**place_piece(int pn, int *coord, char **board, int xandy[]);
char	**remove_piece(int pn, char **board);
int 	solver(char **board, int *coord, int nb, int pn);
char 	**resize(char **board);
void	print_board(char **board);
#endif

