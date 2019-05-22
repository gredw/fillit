/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_store_tetrimino.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 10:41:58 by grougeau          #+#    #+#             */
/*   Updated: 2019/05/22 10:48:36 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	***malloc_3darray(int col, int row)
{
	char	***array;
	int		i;

	i = 0;
	array = (char***)malloc(sizeof(char**) * col);
	if (array == NULL)
		return (NULL);
	while (i < col)
	{
		array[i] = (char**)malloc(sizeof(char*) * row);
		if (array[i] == NULL)
			return (NULL);
		i++;
	}
	return (array);
}

int		open_check(char *filename, char *str)
{
	int	fd;
	int	ret;
	int k;

	k = 20;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (-1);
	ret = read(fd, str, BUFF_SIZE);
	if (ret > 545 || ret == -1 || ret % 21 == 0 || ret < 20)
		return (-1);
	str[ret] = '\0';
	while (str && k < ret)
	{
		if (str[k] != '\n')
			return (-1);
		k += 21;
	}
	if (close(fd) == -1)
		return (-1);
	return ((ret / 21) + 1);
}

char	***store_tretrimino(char *filename, int *ret)
{
	char	str[BUFF_SIZE + 1];
	char	***tab;
	int		row;
	int		col;
	int		i;

	i = 0;
	col = 0;
	if ((*ret = open_check(filename, str)) == -1)
		return (NULL);
	tab = malloc_3darray(*ret, 4);
	while (col < *ret)
	{
		row = 0;
		while (row < 4)
		{
			tab[col][row] = ft_strsub(str, i, 5);
			row++;
			i += 5;
		}
		i++;
		col++;
	}
	return (tab);
}

void	free_tetrimino(char ***tab, int nb)
{
	int col;
	int row;

	col = 0;
	while (col < nb)
	{
		row = 0;
		while (row < 4)
		{
			ft_strdel(&tab[col][row]);
			row++;
		}
		ft_memdel((void *)&tab[col]);
		col++;
	}
	ft_memdel((void *)&tab);
}

void	clear_all(char ***tetrimino, int *coord, int nb, char **board)
{
	free_tetrimino(tetrimino, nb);
	free_coordinates(coord);
	free_board(board);
}
