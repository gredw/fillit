/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:42:02 by grougeau          #+#    #+#             */
/*   Updated: 2019/03/05 18:28:53 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	size_t			len;
	char			*cp;

	i = 0;
	if (s)
	{
		len = ft_strlen(s) - 1;
		while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		{
			i++;
			if (s[i] == '\0')
			{
				cp = (char *)malloc(sizeof(char) * 1);
				cp[0] = '\0';
				return (cp);
			}
		}
		while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
			len--;
		cp = (ft_strsub(s, i, (size_t)(len - i + 1)));
		return (cp);
	}
	return (NULL);
}
