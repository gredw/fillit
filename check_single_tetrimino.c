/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_single_tetrimino.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <grougeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:17:10 by grougeau          #+#    #+#             */
/*   Updated: 2019/04/17 19:19:17 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft/ft_strjoin.c"
#include "libft/libft.h"
#define BUFF_SIZE 5

char	***store_tretrimino(char *filename) //put one tetromino in each box of my 3d array
{
	int 	ret;
	int 	fd;
	char 	*str;
	char 	tab[30][5][6];
	int 	row;
	int count;

	row = 0;
	count = 0;
	fd = open (filename, O_RDONLY);
	while (((ret= read(fd, str, BUFF_SIZE))>= 0) && row < 5)
	{
		str[ret] = '\0';
		tab[0][row]= str;
		tab[0][row][5]= '\0';
		printf("read line:%s\n", tab[0][row]); //PRINT	
		row++;
	}
	return(tab);
}

int	count_hashtagdot (char ***tab) // check if each tetrimino  block has 4# && 12.
{
	int col;
	int row;
	int z;
	int count;
	int dot;

	row = 0;
	col = 0;
	z = 0;
	count = 0;
	dot = 0;
	while (row < 5)
	{
		while (z < 5)
		{
			if (tab[col][row][z] == '#')
				count++;
			if (tab[col][row][z] == '.')
				dot++;
			z++;
		}
		row++;
		printf("nb # =%d && .=%d ", count, dot); //PRINT
		if (count == 4 && dot == 12)
		{	
			printf("return 1\n"); //PRINT
			return (1);
		}
	printf("return -1\n");	//PRINT
	return (-1);
}
    
int	check_validchar(char ***tab) // check if all char are ok
{
	int row;
	int col;
	int z;

	row = 0;
	col = 0;
	z = 0;

	while (row < 5)
	{
		if (tab[col][row][4] != '\n')
		{
			printf("No new line at the end return -1\n"); //PRINT
			return (-1);
		}
		while (z < 5)
		{
			if (tab[col][row][z] != '.' || tab[col][row][z] != '#' || tab[col][row][z] != '\n')
			{
				printf("Not only . and # return -1\n");//PRINT
				return(-1);
			}
			z++;
		}
		row++;
	}
	printf("only . && # return 1\n") //PRINT
	return(1);
}

int check_nbconnexions(char ***tab)
{
	int row;
	int col;
	int z;
	int count;

	row = 0;
    	col = 0;
    	z = 0;

	while (row < 5)
    	{
		while(z < 5)
        	{
			if (tab[col][row][z] == '#' && row > 0 && row < 3 && z > 0 && z < 3)
			{
				if (tab[col][row][z + 1] == '#' ||tab[col][row][z - 1] == '#' || tab[col][row + 1][z] == '#' ||  tab[col][row - 1][z] == '#')
				count++;
           		}
        		if (tab[col][row][z] == '#' && row == 0)
          		{	
               		 	if (tab[col][row][z + 1] == '#' ||tab[col][row][z - 1] == '#' || tab[col][row + 1][z] == '#')
				count++;
         		}
			if (tab[col][row][z] == '#' && row == 3)
           		{
                 		if (tab[col][row][z + 1] == '#' ||tab[col][row][z - 1] == '#' || tab[col][row - 1][z] == '#' )
                    		count++;
           		}
			if (tab[col][row][z] == '#' && z == 3)
			{
              			if (tab[col][row][z + 1] == '#' ||tab[col][row][row + 1] == '#' || tab[col][row - 1][z] == '#' )
				count++;
          		}
			if (tab[col][row][z] == '#' && z == 0)
		{
              		if (tab[col][row][z + 1] == '#' ||tab[col][row][row + 1] == '#' || tab[col][row - 1][z] == '#' )
				count++;
          	}
		z++;
        }
	row++;
	}
	if (count < 6)
	{
		printf("nb of connexions=%d return -1\n", count); //PRINT
		return(-1);
	}
	printf("nb of connexions=%d return 1\n", count); //PRINT
	return(1);
}
    
int	check_tetrimino(char ***tab)
{
	if (check_validchar(tab) == -1)
		return (-1);
	if (count_hashtagdot(tab) == -1)
		return (-1);
	if (check_nbconnexions(tab) == -1)
		return (-1);
	return (0);
}

int main (int argv, char**argc)
{
	int ret;
	int fd;
	
	
	
