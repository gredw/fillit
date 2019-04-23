/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 10:00:38 by grougeau          #+#    #+#             */
/*   Updated: 2019/03/12 14:47:44 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char		*mem;
	size_t		i;

	i = 0;
	mem = malloc(sizeof(mem) * size);
	if (mem == NULL)
		return (NULL);
	else
		while (i < size)
		{
			mem[i] = 0;
			i++;
		}
	return ((void *)mem);
}
