/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_multiple_tetrimino.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 10:09:04 by grougeau          #+#    #+#             */
/*   Updated: 2019/05/22 10:16:49 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	count_hashtagdot(char **tab)
{
	int row;
	int z;
	int count;
	int dot;

	row = 0;
	count = 0;
	dot = 0;
	while (row < 4)
	{
		z = 0;
		while (z < 5)
		{
			if (tab[row][z] == '#')
				count++;
			if (tab[row][z] == '.')
				dot++;
			z++;
		}
		row++;
	}
	if (count == 4 && dot == 12)
		return (1);
	return (-1);
}

int	check_validchar(char **tab)
{
	int row;
	int z;

	row = 0;
	while (row < 4)
	{
		if (tab[row][4] != '\n')
			return (-1);
		z = 0;
		while (z < 4)
		{
			if (tab[row][z] != '.' && tab[row][z] != '#')
				return (-1);
			z++;
		}
		row++;
	}
	return (1);
}

int	check_nbconnexions(char **tab)
{
	int row;
	int z;
	int count;

	count = 0;
	row = 0;
	while (row < 4)
	{
		z = 0;
		while (z < 4)
		{
			if (tab[row][z] == '#')
			{
				if (z < 3 && tab[row][z + 1] == '#')
					count++;
				if (z > 0 && tab[row][z - 1] == '#')
					count++;
			}
			z++;
		}
		row++;
	}
	return ((count + (check_nbconnexions_bis(tab)) < 6) ? -1 : 1);
}

int	check_nbconnexions_bis(char **tab)
{
	int row;
	int z;
	int count;

	count = 0;
	z = 0;
	while (z < 4)
	{
		row = 0;
		while (row < 4)
		{
			if (tab[row][z] == '#')
			{
				if (row > 0 && tab[row - 1][z] == '#')
					count++;
				if (row < 3 && tab[row + 1][z] == '#')
					count++;
			}
			row++;
		}
		z++;
	}
	return (count);
}

int	check_tetrimino(char ***tab, int *ret)
{
	int col;

	col = 0;
	if (tab == NULL)
		return (-1);
	while (col < *ret)
	{
		if (check_validchar(tab[col]) == -1)
			return (-1);
		if (count_hashtagdot(tab[col]) == -1)
			return (-1);
		if (check_nbconnexions(tab[col]) == -1)
			return (-1);
		col++;
	}
	return (1);
}
