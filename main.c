/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:24:36 by grougeau          #+#    #+#             */
/*   Updated: 2019/05/16 19:21:34 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/ft_putstr.c"
#include "libft/ft_putchar.c"
#include "libft/ft_putchar_fd.c"
#include "libft/ft_strsub.c"
#include "libft/ft_strdel.c"
#include "libft/ft_memdel.c"

int solver2(char *filename)
{
	int ret;
	int a;
	int *nb;
	char ***array;
	char **board;
	int *coord;
	int pn = 0;
	int width;

	nb = &a;
	if (((array = store_tretrimino(filename, nb))== NULL) || ((ret = check_tetrimino(array, nb))== -1))
	{	
		ft_putstr("error\n");
		return (-1);
	}
	coord = coordinates(*nb, array);
	width = board_width(*nb);
	board = define_boardsize (width);
	while (solver(&*board, coord, *nb, pn) == 0)
		board = resize(&*board);
	print_board(board);
	clear_all(array, coord, *nb, board);

	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{	
		ft_putstr("error\n");
			return (-1);
	}
	else
		solver2(argv[1]);
	return(0);
}
	
