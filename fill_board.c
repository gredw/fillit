/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:15:34 by grougeau          #+#    #+#             */
/*   Updated: 2019/05/13 19:11:29 by grougeau         ###   ########.fr       */
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

int	fit_on_board(int width, int pn, int *coord,int *xandy, char **board)
{
	int i;
	int j;
	int row;
	int col;	
	int pathx;
	int pathy;
	int width;

	row = 0;
	col = 0;
	width = board_width_bis(board);
	pathx = xandy[0] - coord[i];
	pathy = xandy[1] - coord[j];
	i = pn * 8;
	j = pn * 8 + 1;

	while (j < (pn * 8 + 7))
	{
		if(coord[i] + pathx < 0 || coord[i] + pathx > width || coord[j] + pathy < 0 || coord[j] + pathx > width || board[coord[i] + pathx][coord[j] + pathy] != '.')
			return(-1);	
		i =+ 2;
		j =+ 2;
	}
	return(0);
}

char **place_piece(int pn, int *coord, char**board, int xandy[])
{
	int i;
	int j;
	int pathx;
	int pathy;

	pathx = xandy[0] - coord[i];
	pathy = xandy[1] - coord[j];
	i = pn * 8;
	j = pn * 8 + 1;

	while (j  < (pn * 8 + 7))
	{
		board[coord[i] + pathx][coord[j] + pathy] = 65 + pn;
		i += 2;
		j += 2;
	}
	return(board);
}

	
