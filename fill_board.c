/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:15:34 by grougeau          #+#    #+#             */
/*   Updated: 2019/05/14 17:20:03 by grougeau         ###   ########.fr       */
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
				printf("x =%d & y=%d\n", xandy[0], xandy[1]);//PRINT
				return (xandy);
			}
			row++;
		}
		row = 0;
		col++;
	}
	return (NULL); 
}

int	fit_on_board(int pn, int *coord,int *xandy, char **board)
{
	int i;
	int j;
	int pathx;
	int pathy;
	int width;

	i = pn * 8;
	j = pn * 8 + 1;
	width = board_width_bis(board);
	pathx = xandy[0] - coord[i];
	pathy = xandy[1] - coord[j];
	
	while (j <= (pn * 8 + 7))
	{
		printf("piece %d%d\n", coord[i], coord[j]);
		if ((coord[i] + pathx) < 0 || (coord[i] + pathx) >= width || (coord[j] + pathy) < 0 || (coord[j] + pathy) >= width || board[coord[i] + pathx][coord[j] + pathy] != '.')
		{
				printf("piece %d%d NOT fitting\n", coord[i], coord[j]);
				return(-1);
		}	
		i += 2;
		j += 2;
	}
	printf("piece fits for xandy[0]=%d & xandy[1]=%d\n", xandy[0], xandy[1]);//PRINT
	return(0);
}

char **place_piece(int pn, int *coord, char **board, int xandy[])
{
	int i;
	int j;
	int pathx;
	int pathy;
	int k = 0;
	int l;

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
	while (k < board_width_bis(board)) // PRINT
	{
		l=0;
		while ( l < board_width_bis(board))
		{
			printf("%c", board[k][l]);
			l++;
		}
		k++;
	}
	return(board);
}

char **remove_piece( int pn, char **board)
{
 	char letter;
	int i;
	int j;
	int k;
	int l;
	k = 0;
 	letter = pn + 65;
	while (i < board_width_bis(board))
	{
		j=0;
		while (j < board_width_bis(board))
		{
			if ( board[i][j] == letter)
			{ 
				board[i][j] = '.';
			}
			l++;
		}
		k++;
	}

	while (k < board_width_bis(board)) // PRINT
	{
		l=0;
		while ( l < board_width_bis(board))
		{
			printf("%c", board[k][l]);
			l++;
		}
		k++;
	}

	return(board);
}

