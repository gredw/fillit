/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 15:34:59 by grougeau          #+#    #+#             */
/*   Updated: 2019/05/22 10:41:22 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	solver(char **board, int *coord, int nb, int pn)
{
	int xandy[2];
	int width;

	width = board_width_bis(board);
	xandy[0] = 0;
	if (pn >= nb)
		return (1);
	while (xandy[0] < width)
	{
		xandy[1] = 0;
		while (xandy[1] < width)
		{
			if (fit_on_board(pn, coord, xandy, board) == 1)
			{
				place_piece(pn, coord, board, xandy);
				if (solver(board, coord, nb, pn + 1) == 1)
					return (1);
				else
					remove_piece(pn, board);
			}
			xandy[1]++;
		}
		xandy[0]++;
	}
	return (0);
}
