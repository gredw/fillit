/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_multiple_tetrimino.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <grougeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:17:10 by grougeau          #+#    #+#             */
/*   Updated: 2019/05/02 16:54:20 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


char ***malloc_3darray(int col, int row, int z)
{
	char ***array;
	int i;
	int j;

	i = 0;
	j = 0;
	array = (char***)malloc(sizeof(char**) * col);
	if (array == NULL)
		return (NULL);
	while(i < col)
	{
		array[i] = (char**)malloc(sizeof(char*)*row);
		if (array[i] == NULL)
		return (NULL);
		while (j < row)
		{
			array[i][j] = (char*)malloc(sizeof(char) * (z + 1));
			if (array[i] == NULL)
				return (NULL);
			j++;
		}
		i++;
	}
	return (array);
}

int		open_check(char *filename, char *str)
{
	int		fd;
	int		ret;
	int 		k;

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
	char 	str[BUFF_SIZE + 1];
	char 	***tab;
	int 	row;
	int	col;
	int 	i;
	i = 0;
	col = 0;
	if ((*ret = open_check(filename, str)) == -1)
		return (NULL);
	tab = malloc_3darray(27, 5, 5);
	while (col < 26)
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
	return(tab);
} 
		
int	count_hashtagdot (char **tab) // check if each tetrimino  block has 4# && 12.
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
		z =  0;
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
int	check_validchar(char **tab) // check if all char are ok
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
				return(-1);
			z++;
		}
		row++;
	}
	return(1);
}

int check_nbconnexions(char **tab)
{
	int row;
	int z;
	int count;

	count = 0;
	
	row = 0;
	while (row < 4)
    	{
		z = 0;
		while(z < 4)
        	{
			if (tab[row][z] == '#') 	
			{	
				if ( z < 3 && tab[row][z + 1] == '#') 
					count++;
               			if (z > 0 && tab[row][z - 1] == '#') 
					count++;
			}
			z++;
		}
		row++;
	}
	z = 0;
	while (z < 4)
	{
		row = 0;
		while(row < 4)
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
	if (count < 6)
		return(-1);
	return(1);
}
    
int	check_tetrimino(char ***tab, int *ret)
{
	int col;

	col = 0;
	if (tab == NULL)
		return (-1);
	while ( tab[col] && col < *ret)
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
