/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:39:49 by grougeau          #+#    #+#             */
/*   Updated: 2019/02/14 17:36:24 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char*)src)[i] == ((unsigned char)c))
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			return ((dst + i + 1));
		}
		else
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (NULL);
}
