/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:15:34 by grougeau          #+#    #+#             */
/*   Updated: 2019/05/22 11:46:05 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fit_on_board(int pn, int *coord, int *xandy, char **board)
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
		if ((coord[i] + pathx) < 0 || (coord[i] + pathx) >= width
				|| (coord[j] + pathy) < 0 || (coord[j] + pathy) >= width
				|| board[coord[i] + pathx][coord[j] + pathy] != '.')
			return (-1);
		i += 2;
		j += 2;
	}
	return (1);
}

char	**place_piece(int pn, int *coord, char **board, int xandy[])
{
	int i;
	int j;
	int pathx;
	int pathy;

	i = pn * 8;
	j = pn * 8 + 1;
	pathx = xandy[0] - coord[i];
	pathy = xandy[1] - coord[j];
	while (j <= (pn * 8 + 7))
	{
		board[coord[i] + pathx][coord[j] + pathy] = (65 + pn);
		i += 2;
		j += 2;
	}
	return (board);
}

char	**remove_piece(int pn, char **board)
{
	char	letter;
	int		i;
	int		j;

	i = 0;
	letter = pn + 65;
	while (i < board_width_bis(board))
	{
		j = 0;
		while (j < board_width_bis(board))
		{
			if (board[i][j] == letter)
				board[i][j] = '.';
			j++;
		}
		i++;
	}
	return (board);
}

void	print_board(char **board)
{
	int k;
	int j;

	k = 0;
	j = 0;
	while (k < board_width_bis(board))
	{
		j = 0;
		while (j <= board_width_bis(board))
		{
			ft_putchar(board[k][j]);
			j++;
		}
		k++;
	}
}
