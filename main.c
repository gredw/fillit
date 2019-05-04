/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:24:36 by grougeau          #+#    #+#             */
/*   Updated: 2019/05/02 16:49:10 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*#include "libft/libft.h"
#include "define_boardsize.c"
#include "check_multiple_tetrimino.c"
*/


int	main(int argc, char **argv)
{
	int ret;
	int a;
	int *nb;
	nb = &a;
	char ***array;
	char **board;
	int i = 0;
	int k = 0;

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
		
		coordinates(*nb, array);
		board = define_boardsize (*nb);
		get_board_coordinates(board, board_width(*nb));
		
			
		

	}
	return (0);
}
	
