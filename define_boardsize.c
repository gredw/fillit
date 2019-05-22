/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_boardsize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:24:01 by grougeau          #+#    #+#             */
/*   Updated: 2019/05/22 12:56:11 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		board_width(int nb)
{
	int i;

	i = 0;
	nb = nb * 4;
	while (i * i < nb)
		i++;
	return (i);
}

int		board_width_bis(char **board)
{
	int i;

	i = 0;
	while (board[0][i] != '\n')
		i++;
	return (i);
}

char	**define_boardsize(int i)
{
	char	**board;
	int		k;
	int		j;

	k = 0;
	board = (char**)malloc(sizeof(char*) * i);
	if (board == NULL)
		return (NULL);
	while (k < i)
	{
		board[k] = (char*)malloc(sizeof(char) * (i + 2));
		board[k][i] = '\n';
		board[k][i + 1] = '\0';
		if (board[k] == NULL)
			return (NULL);
		j = 0;
		while (j < i)
		{
			board[k][j] = '.';
			j++;
		}
		k++;
	}
	return (board);
}

char	**resize(char **board)
{
	int width;

	width = board_width_bis(board) + 1;
	free_board(board);
	board = define_boardsize(width);
	return (board);
}

void	free_board(char **board)
{
	int col;
	int width;

	width = board_width_bis(board);
	col = 0;
	while (col < width)
	{
		ft_strdel(&board[col]);
		col++;
	}
	free(board);
}
