/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:15:34 by grougeau          #+#    #+#             */
/*   Updated: 2019/05/16 19:22:17 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
		//printf("piece %d%d\n", coord[i], coord[j]);//PRINT
		if ((coord[i] + pathx) < 0 || (coord[i] + pathx) >= width || (coord[j] + pathy) < 0 || (coord[j] + pathy) >= width || board[coord[i] + pathx][coord[j] + pathy] != '.')
		{
				//printf("piece %d%d NOT fitting\n", coord[i], coord[j]);
				return(-1);
		}	
		i += 2;
		j += 2;
	}
	printf("Tetri fits for xandy[0]=%d & xandy[1]=%d\n", xandy[0], xandy[1]);//PRINT
	return(1);
}

char **place_piece(int pn, int *coord, char **board, int xandy[])
{
	int i;
	int j;
	int pathx;
	int pathy;
	int k = 0;
	int l;

	i = pn * 8;
	j = pn * 8 + 1;
	pathx = xandy[0] - coord[i];
	pathy = xandy[1] - coord[j];

	while (j  <= (pn * 8 + 7))
	{
		board[coord[i] + pathx][coord[j] + pathy] = (65 + pn);
		i += 2;
		j += 2;
	}
	return(board);
}

char **remove_piece( int pn, char **board)
{
	printf("remove piece\n");
 	char letter;
	int i;
	int j;
	i = 0;
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
			j++;
		}
		i++;
	}
	printf("remove SHIT\n");
	return (board);
}

void	print_board(char **board)
{
	int k = 0;
	int j = 0;
	printf("board width = %d\n", board_width_bis(board));
	while (k < board_width_bis(board))
	{
		j = 0;
		while (j <= board_width_bis(board))
		{
			printf("%c", board[k][j]);
			j++;
		}
		k++;
	}
}

