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

int	main(int argc, char **argv)
{
	int ret;
	int a;
	int *nb;
	nb = &a;
	char ***array;
	char **board;
	int *coord;
	int pn = 0;
	int width;
	if (argc)
	{
		array = store_tretrimino(argv[1], nb);
		if ((array == NULL) || ((ret = check_tetrimino(array, nb))== -1))
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
	}
	return (0);
}
	
