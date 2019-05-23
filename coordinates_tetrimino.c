/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates_tetrimino.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 15:22:15 by grougeau          #+#    #+#             */
/*   Updated: 2019/05/22 13:03:12 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	*coordinates2(int nb, char ***tetriminos)
{
	int col;
	int *coord;
	int i;

	i = 0;
	coord = (int *)malloc(sizeof(int) * nb * 4 * 2);
	col = 0;
	while (col < nb)
	{
		i = coordinates1(tetriminos[col], coord, i);
		col++;
	}
	return (coord);
}

int	coordinates1(char **tetriminos, int *coord, int i)
{
	int row;
	int z;

	row = 0;
	while (row < 4)
	{
		z = 0;
		while (z < 4)
		{
			if (tetriminos[row][z] == '#')
			{
				coord[i] = row;
				i++;
				coord[i] = z;
				i++;
			}
			z++;
		}
		row++;
	}
	return (i);
}

void	free_coordinates(int *coord)
{
	ft_memdel((void *)&coord);
}
