/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:58:25 by grougeau          #+#    #+#             */
/*   Updated: 2019/03/05 18:28:20 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (n == 0)
		return (0);
	else
	{
		i = 0;
		while (i < n && ((unsigned char*)s1)[i] == ((unsigned char*)s2)[i]
				&& s1[i] != '\0' && s2[i] != '\0')
		{
			i++;
		}
		if (i == n)
			return (((unsigned char*)s1)[i - 1] - ((unsigned char*)s2)[i - 1]);
		else
			return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
	}
}
