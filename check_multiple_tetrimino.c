/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_single_tetrimino.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <grougeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:17:10 by grougeau          #+#    #+#             */
/*   Updated: 2019/04/24 17:07:51 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#include "libft/ft_strjoin.c"
#include "libft/libft.h"
#include "libft/ft_strlen.c"
#include "libft/ft_strsub.c"
#include "libft/ft_strcpy.c"
#define BUFF_SIZE 546


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
	printf("str=%s\n", str); //PRINT
	tab = malloc_3darray(27, 5, 5);
	while (col < 26)
	{
		row = 0;
		while (row < 4)
		{
			tab[col][row] = ft_strsub(str, i, 5);
			printf("tab[%d][%d]:%s",col, row, tab[col][row]); //PRINT	
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
	printf("nb # =%d && .=%d ", count, dot); //PRINT
	if (count == 4 && dot == 12)
	{	
		printf("return 1\n"); //PRINT
		return (1);
	}
	printf("return -1\n");	//PRINT
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
		{
			printf("ligne lu = %s No new line at the end return -1\n", tab[row]); //PRINT
			return (-1);
		}
		z = 0;
		while (z < 4)
		{
			if (tab[row][z] != '.' && tab[row][z] != '#')
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

int check_nbconnexions(char **tab)
{
	int row;
//	int col;
	int z;
	int count;

	count = 0;
//	col = 0;
	
//	while (col < 26)
//	{
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
	//	col++;
//	}
	
//	col = 0;

//	while (col < 26)
//	{
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
//		col++;
//	}
	if (count < 6)
	{
		printf("nb of connexions=%d return -1\n", count); //PRINT
		return(-1);
	}
	printf("nb of connexions=%d return 1\n", count); //PRINT
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

/*int main (int argc, char **argv)
{
	int ret;
	int a;
	int *nb;
	nb = &a;
	char ***array;
	int i = 0;
	if (argc)
	{
		array = store_tretrimino(argv[1], nb);
		if (array == NULL)
		{
			printf("ret = -1\n");//PRINT
			return (-1);
		}
	//	while (i < 5)
	//	{
	//		printf("array[0][%d] =%s\n",i, array[0][i]);//PRINT
	//		i++;	

	//	}
		ret = check_tetrimino(array, nb);
		printf("ret = %d\n", ret);//PRINT
	}
	return (0);
}
*/
