/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:49:27 by grougeau          #+#    #+#             */
/*   Updated: 2019/02/19 12:17:53 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (s1 && s2)
	{
		d = (char *)malloc(sizeof(*d) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (d == NULL)
			return (NULL);
		else
		{
			while (s1[++i])
				d[i] = s1[i];
			while (s2[j])
			{
				d[i] = s2[j++];
				i++;
			}
			d[i] = '\0';
		}
		return (d);
	}
	return (NULL);
}
