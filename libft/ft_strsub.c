/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:26:24 by grougeau          #+#    #+#             */
/*   Updated: 2019/02/27 16:47:49 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (s)
	{
		sub = (char *)malloc(sizeof(char) * (len + 1));
		if (sub == NULL)
			return (NULL);
		else
		{
			while (i < len && s[start])
			{
				sub[i] = s[start];
				i++;
				start++;
			}
			sub[i] = '\0';
			return (sub);
		}
	}
	else
		return (NULL);
}
