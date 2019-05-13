/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:15:34 by grougeau          #+#    #+#             */
/*   Updated: 2019/05/13 16:31:39 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*int *get_boardcoordinates(char **board, int width)
{
	int row;
	int col;
	int *xandy;

	xandy = (int *)malloc(sizeof(int) * 2);
	col= 0;
	while (col < width)
	{
		row = 0;
		while (row < width)
		{
			if(board[col][row] == '.')
			{
				xandy[0] = col;
				xandy[1] = row;
				printf("x =%d & y=%d\n", xandy[0], xandy[1]);
				return (xandy);
			}
			row++;
		}
		col++;
	}
	return (NULL); 
}*/

int *get_boardcoordinates(char **board, int width, int row, int col)
{
	int *xandy;

	xandy = (int *)malloc(sizeof(int) * 2);
	while (col < width)
	{
		while (row < width)
		{
			if(board[col][row] == '.')
			{
				xandy[0] = col;
				xandy[1] = row;
				printf("x =%d & y=%d\n", xandy[0], xandy[1]);
				return (xandy);
			}
			row++;
		}
		row = 0;
		col++;
	}
	return (NULL); 
}

int	fit_on__board(char **board, char ***tetromino, int nb)
{
	int i;
	int j;
	int row;
	int col;	
	int width;
	int *coord;
	int *xandy;
	int pathx;
	int pathy;

	row = 0;
	col = 0;
	width = board_width(nb);
	coord = coordinates(nb, tetromino);
	xandy = get_board_coordinates(board, width, row, col);
	pathx = xandy[0] - coord[i];
	pathy = xandy[1] - coord[j];
	i = 0;
	j = 1;
	while (j < 8)
	{
		if(coord[i] + pathx < 0 || coord[i] + pathx > width || coord[j] + pathy < 0 || coord[j] + pathx > width || board[coord[i] + pathx][coord[j] + pathy] != '.')
			return(-1);	
		i =+ 2;
		j =+ 2;
	}
	return(0);
}

			
	
	
