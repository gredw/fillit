/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_boardsize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:24:01 by grougeau          #+#    #+#             */
/*   Updated: 2019/04/24 18:19:20 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
*/
#include "fillit.h"

char **define_boardsize(int nb)
{
	char **board;
	int i;
	int k;	

	i = 0;
	k=0;
int j = 0;
	nb = nb * 4;
	while (i * i < nb)	
		i++;
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


