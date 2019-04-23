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
#include "libft/ft_strlen.c"
#include "libft/ft_strcpy.c"
#define BUFF_SIZE 5


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
	//	if (array[i] == NULL)
	//		return (NULL);
		while (j < row)
		{
			array[i][j] = (char*)malloc(sizeof(char) * (z + 1));
	//		if (array[i] == NULL)
	//			return (NULL);
			j++;
		}
		i++;
	}
	return (array);
}

char	***store_tretrimino(char *filename) //put one tetromino in each box of my 3d array
{
	int 	ret;
	int 	fd;
	char 	str[BUFF_SIZE + 1];
	char 	***tab;
	int 	row;
	int	col;
	int 	count;

	count = 0;
	col =0;
	fd = open (filename, O_RDONLY);
	tab = malloc_3darray(2, 5, 5);
	while (col < 1)
	{
		row = 0;
		while (((ret= read(fd, str, BUFF_SIZE))> 0) && row < 5)
		{
			str[ret] = '\0'; // sure de ca?
			ft_strcpy(tab[0][row], str);
			tab[0][row][5]= '\0';
			printf("read line:%s\n", tab[col][row]); //PRINT	
			row++;
			count++;
		}
		col++;
	}
	printf("total nb of lines=%d\n", count);//PRINT
	return(((count % 5 )== 0 || count > 129) ? NULL : tab);
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
	count = 0;
	dot = 0;
	while (row < 5)
	{
		z =  0;
		while (z < 5)
		{
			if (tab[col][row][z] == '#')
				count++;
			if (tab[col][row][z] == '.')
				dot++;
			z++;
		}
		row++;
	}
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

	while (row < 4)
	{
		if (tab[col][row][4] != '\n')
		{
			printf("ligne lu = %s No new line at the end return -1\n", tab[col][row]); //PRINT
			return (-1);
		}
		while (z < 4)
		{
			if (tab[col][row][z] != '.' && tab[col][row][z] != '#')
			{
				printf("Not only . and # return -1\n");//PRINT
				return(-1);
			}
			z++;
		}
		row++;
	}
	printf("only . && # return 1\n"); //PRINT
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
	count = 0;
	while (row < 4)
    	{
		z = 0;
		while(z < 4)
        	{
			if (tab[col][row][z] == '#') 	
			{
				if ( z < 3 && tab[col][row][z + 1] == '#') 
					count++;
               		 	if (z > 0 && tab[col][row][z - 1] == '#') 
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
			
			if (tab[col][row][z] == '#') 	
			{
				if (row > 0 && tab[col][row - 1][z] == '#')
                    			count++;
              			if (row < 3 && tab[col][row + 1][z] == '#')
					count++;
          	 	}
			row++;
      		  }
		z++;
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
	if (tab == NULL)
		return (-1);
	if (check_validchar(tab) == -1)
		return (-1);
	if (count_hashtagdot(tab) == -1)
		return (-1);
	if (check_nbconnexions(tab) == -1)
		return (-1);
	return (1);
}

int main (int argc, char **argv)
{
	int ret;
	char ***array;
	int i = 0;
	if (argc)
	{
		array = store_tretrimino(argv[1]);
	/*	while (i < 5)
		{
			printf("array[0][%d] =%s\n",i, array[0][i]);//PRINT
			i++;	

		}*/
		ret = check_tetrimino(array);
		printf("ret = %d\n", ret);//PRINT
	}
	return (0);
}

