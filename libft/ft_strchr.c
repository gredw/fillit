/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:13:21 by grougeau          #+#    #+#             */
/*   Updated: 2019/02/14 14:55:38 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (s[0] == c)
			return ((char *)s);
		if (s[0] == '\0')
			return (NULL);
		if (s[1] == c)
			return ((char *)(s + 1));
		if (s[1] == '\0')
			return (NULL);
		if (s[2] == c)
			return ((char *)(s + 2));
		if (s[2] == '\0')
			return (NULL);
		if (s[3] == c)
			return ((char *)(s + 3));
		if (s[3] == '\0')
			return (NULL);
		if (s[4] == c)
			return ((char *)(s + 4));
		if (s[4] == '\0')
			return (NULL);
		s += 5;
	}
}
