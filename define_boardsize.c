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
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int		open_check(char *filename)
{
	int		fd;
	int		ret;
	int 		k;
	char str[547];

	k = 20;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (-1);
	ret = read(fd, str, 546);
	if (ret > 545 || ret == -1 || ret % 21 == 0 || ret < 20)
		return (-1);
	str[ret] = '\0';
	while (k < ret)
	{
		if (str[k] != '\n')
			return (-1);
		k += 21;
	}
	if (close(fd) == -1)
		return (-1);
	return ((ret / 21) + 1);
}

char **define_boardsize(char *filename)
{
	int nb;
	char **board;
	int i;
	int k;	

	i = 0;
	k=0;
	nb = open_check(filename) * 4;
	while (i * i < nb)	
		i++;
	board = (char**)malloc(sizeof(char*) * i);
	if (board = NULL)
		return (NULL);
	while (k < i)
	{
		board[k] = (char*)malloc(sizeof(char) *i);
		k++;
	}
	if (board[k] = NULL)
		return (NULL);
	return (board);
}


int main(int argc, char **argv)
{
	int nb;

	nb = define_boardsize( argv[1]);
	printf(" nb = %d\n", nb);
}
