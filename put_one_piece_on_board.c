/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_one_piece_on_board.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:24:20 by grougeau          #+#    #+#             */
/*   Updated: 2019/04/30 18:26:30 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int put_one_piece_on_board(char **board, char***array, int nb)
{
	int z;
	int row;
	int col;
	int i;
	int j;
	//int path[26];
	int p1;
	int p2;

	col = 0;
	i = 0;
	j = 0;
	p =0;
	while (array[col] < nb)
	{
		row = 0;
		while (row < 4)
		{
			z = 0;
			while (z < 4)
			{
				if(array[col][row][z] == '#')
				{
					while (board[i][j] < nb)
					{	
						if(board[i][j] == '.')
						{
							p1 = z - j;
							break;
						}
						j++;
					}
					i++;
				}
				z++;
			}
			row++;
		}
					
