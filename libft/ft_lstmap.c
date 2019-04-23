/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grougeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:45:38 by grougeau          #+#    #+#             */
/*   Updated: 2019/03/06 15:59:39 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *begin;
	t_list *new;

	begin = (*f)(lst);
	new = begin;
	if (lst == NULL)
		return (NULL);
	else
	{
		while (lst->next)
		{
			lst = lst->next;
			new->next = (*f)(lst);
			new = new->next;
		}
		return (begin);
	}
}
