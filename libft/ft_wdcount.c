/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdcount.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:45:53 by grougeau          #+#    #+#             */
/*   Updated: 2019/02/26 16:59:54 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wdcount(char const *str, char c)
{
	int		i;
	int		count;
	size_t	del;

	i = 0;
	count = 1;
	del = 0;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
			count++;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			del++;
		i++;
	}
	if (del == ft_strlen(str) || str[0] == c)
		count = count - 1;
	return (count);
}
