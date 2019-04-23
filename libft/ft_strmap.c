/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:04:40 by grougeau          #+#    #+#             */
/*   Updated: 2019/02/18 14:47:34 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*mem;

	i = 0;
	if (s)
	{
		mem = (char*)malloc(sizeof((*f)(s[i])) * (ft_strlen(s) + 1));
		if (mem == NULL)
			return (NULL);
		else
		{
			while (s[i])
			{
				mem[i] = (*f)(s[i]);
				i++;
			}
			mem[i] = '\0';
			return (mem);
		}
	}
	return (NULL);
}
