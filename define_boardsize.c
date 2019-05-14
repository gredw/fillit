/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_boardsize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:24:01 by grougeau          #+#    #+#             */
/*   Updated: 2019/05/13 19:11:38 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
*/
#include "fillit.h"

int 	board_width(int nb)
{
	int i;

	i = 0;
	nb = nb * 4;
	while (i * i < nb)	
		i++;
	return (i);
}
	
int board_width_bis(int **board)
{
	int i;
	
	i = 0;
	while (board[0][i] != '\n')
		i++;
	return (i);
}

char **define_boardsize(int nb)
{
	char **board;
	int k;
	int i;	

	
	k=0;
	int j = 0;
	i = board_width(nb);
	board = (char**)malloc(sizeof(char*) * i);
	if (board == NULL)
		return (NULL);
	while (k < i)
	{
		board[k] = (char*)malloc(sizeof(char) *(i + 2));
		board[k][i] = '\n';
		board[k][i + 1] = '\0';	
		if (board[k] == NULL)
			return (NULL);
		j = 0;
		while ( j < i)
		{	
			board[k][j] = '.';
			j++;
		}
		k++;
	}

	k = 0;
	while (k < i)
	{
		j = 0;
		while( j < (i+ 1))
		{
		printf("%c", board[k][j]);
		j++;
		}	
	k++;
	}
	return (board);
}


