/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:44:55 by grougeau          #+#    #+#             */
/*   Updated: 2019/02/26 17:51:27 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_arraystr(char const *s, char c)
{
	char	**array;
	int		*substrlen;
	int		i;

	i = 0;
	if (s && c)
	{
		array = (char **)malloc(sizeof(char) * (ft_wdcount(s, c) + 1));
		if (array == NULL)
			return (NULL);
		substrlen = ft_wdlen(s, c);
		while (i < ft_wdcount(s, c))
		{
			array[i] = (char *)malloc(sizeof(char) * 1);
			i++;
		}
		return (array);
	}
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		i;
	int		k;
	int		j;

	i = 0;
	j = 0;
	array = ft_arraystr(s, c);
	if (array == NULL)
		return (NULL);
	while (j < ft_wdcount(s, c))
	{
		while (s[i] == c)
			i++;
		k = 0;
		while (s[i] != c && s[i] != '\0')
		{
			array[j][k] = s[i++];
			k++;
		}
		array[j++][k] = '\0';
	}
	array[j] = NULL;
	return (array);
}
