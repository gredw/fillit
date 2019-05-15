/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 15:34:59 by grougeau          #+#    #+#             */
/*   Updated: 2019/05/14 17:20:07 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int solver(char **board, int *coord, int nb, int pn)
{
	int xandy[2];
	int width;

	width = board_width(nb);
	xandy[0] = 0;
	xandy[1] = 0;

	while (xandy[0] < width)
	{
		xandy[1] = 0;
		while (xandy[1] < width)
		{
			if( fit_on_board(pn, coord, xandy, board) == 1)
				place_piece(pn, coord, board, xandy);
			xandy[1]++;
		}
		xandy[0]++;
	}

	return(0);
}
