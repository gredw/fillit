/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:48:15 by grougeau          #+#    #+#             */
/*   Updated: 2019/02/18 14:53:03 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*mem;

	i = 0;
	if (s)
	{
		mem = (char*)malloc(sizeof((*f)(i, s[i])) * (ft_strlen(s) + 1));
		if (mem == NULL)
			return (NULL);
		else
		{
			while (s[i])
			{
				mem[i] = (*f)(i, s[i]);
				i++;
			}
			mem[i] = '\0';
			return (mem);
		}
	}
	return (NULL);
}
