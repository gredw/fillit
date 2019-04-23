/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 13:51:34 by grougeau          #+#    #+#             */
/*   Updated: 2019/02/26 17:53:26 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_calcullen(int nb)
{
	int len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static	char	*ft_ifneg(int len, int n)
{
	char	*str;
	int		sign;
	int		end;

	sign = 0;
	if (n < 0)
	{
		n = n * -1;
		sign = -1;
	}
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	end = len;
	len = len - 1;
	while (len >= 0)
	{
		str[len--] = (n % 10 + 48);
		n = n / 10;
	}
	if (sign == -1)
		str[0] = '-';
	str[end] = '\0';
	return (str);
}

static	char	*ifzero(void)
{
	char	*tmp;
	char	*d;
	int		i;

	i = 0;
	tmp = "0";
	d = ft_strnew(1);
	while (tmp[i] != '\0')
	{
		d[i] = tmp[i];
		i++;
	}
	return (d);
}

char			*ft_itoa(int n)
{
	int		nlen;
	int		i;
	char	*tmp;
	char	*d;

	i = 0;
	tmp = "-2147483648";
	if (n == -2147483648)
	{
		d = ft_strnew(11);
		while (tmp[i] != '\0')
		{
			d[i] = tmp[i];
			i++;
		}
		return (d);
	}
	else if (n == 0 || n == -0)
		return (ifzero());
	else
		nlen = ft_calcullen(n);
	return (ft_ifneg(nlen, n));
}
