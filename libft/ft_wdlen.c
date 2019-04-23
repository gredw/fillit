/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdlen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:49:23 by grougeau          #+#    #+#             */
/*   Updated: 2019/02/26 17:48:03 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_wdlen(char const *str, char c)
{
	int i;
	int k;
	int len;
	int *tab;

	i = 0;
	k = 0;
	tab = (int *)malloc(sizeof(int) * (ft_wdcount(str, c) + 1));
	if (tab == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		len = 0;
		while (str[i] != c && str[i] != '\0')
		{
			len++;
			i++;
		}
		tab[k] = len;
		k++;
	}
	tab[k - 1] = -1;
	return (tab);
}
