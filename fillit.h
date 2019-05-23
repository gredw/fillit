/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 12:58:35 by grougeau          #+#    #+#             */
/*   Updated: 2019/05/22 13:00:42 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# define BUFF_SIZE 546

char	***malloc_3darray(int col, int row);
int		open_check(char *filename, char *str);
char	***store_tretrimino(char *filename, int *ret);
int		count_hashtagdot (char **tab);
int		check_validchar(char **tab);
int		check_nbconnexions(char **tab);
int		check_tetrimino(char ***tab, int *ret);
char	**define_boardsize(int i);
int		*coordinates2(int nb, char ***tetriminos);
int		board_width(int nb);
int		*get_board_coordinates(char **board, int width);
int		board_width_bis(char **board);
int		fit_on_board(int pn, int *coord, int *xandy, char **board);
char	**place_piece(int pn, int *coord, char **board, int xandy[]);
char	**remove_piece(int pn, char **board);
int		solver(char **board, int *coord, int nb, int pn);
char	**resize(char **board);
void	print_board(char **board);
void	free_board(char **board);
void	free_coordinates(int *coord);
void	free_tetrimino(char ***tab, int nb);
void	clear_all(char ***tetrimino, int *coord, int nb, char **board);
int		check_nbconnexions_bis(char **tab);
int		solver2(int *nb, char ***array);
int		checker(char *filename);
int  coordinates1(char **tetriminos, int *coord, int i);

#endif
