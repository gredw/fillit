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
/*#include "libft/libft.h"
#include "define_boardsize.c"
#include "check_multiple_tetrimino.c"
#include <unistd.h>
*/


int	main(int argc, char **argv)
{
	int ret;
	int a;
	int b;
	int *nb;
	nb = &a;
	char ***array;
	char **board;
	int *coord;
	int i = 0;
	int k = 0;
	int row;
	int col;
	int pn = 0;
	int width;
	if (argc)
	{
		array = store_tretrimino(argv[1], nb);
		if (array == NULL)
		{
			printf("ret = -1 error\n");//PRINT
			return (-1);
		}
		ret = check_tetrimino(array, nb);
		printf("ret = %d\n", ret);//PRINT
		
		coord = coordinates(*nb, array);
		width = board_width(*nb);
		board = define_boardsize (width);
		while (solver(&*board, coord, *nb, pn) == 0)
			board = resize(&*board);
	}
	return (0);
}
	
