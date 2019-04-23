/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 15:45:29 by grougeau          #+#    #+#             */
/*   Updated: 2019/03/05 18:27:13 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	else
		while (*haystack)
		{
			if (len < ft_strlen(needle))
				break ;
			j = j - i;
			i = 0;
			while (haystack[i] == needle[i] && needle[i] != '\0' && j < len)
			{
				i++;
				j++;
			}
			if (needle[i] == '\0')
				return ((char *)haystack);
			haystack++;
			j++;
		}
	return (NULL);
}
