/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates_tetrimino.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 15:22:15 by grougeau          #+#    #+#             */
/*   Updated: 2019/05/14 15:54:22 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int *coordinates(int nb, char ***tetriminos)
{
	int col;
	int row;
	int z;
	int i;
	int *coord;

	i = 0;
	coord = (int *) malloc(sizeof(int) * nb * 4 * 2);
	col = 0;
	while (col < nb)
	{
		row = 0;
		while (row < 4)
		{
			z = 0;
			while (z < 4)
			{	
				if (tetriminos[col][row][z] == '#')
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
		col++;
	}
	return(coord);
}
		
void free_coordinates(int *coord)
{
	ft_memdel((void *)&coord);
}

