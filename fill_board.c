/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:15:34 by grougeau          #+#    #+#             */
/*   Updated: 2019/05/02 17:19:39 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int fill_board(int *coordinates, char **board, int width)
{
	int row;
	int col;
	int *tab[2];

	col= 0;
	while (col < width)
	{
		row = 0;
		while (
