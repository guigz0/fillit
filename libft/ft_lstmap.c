/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:50:46 by gdalard           #+#    #+#             */
/*   Updated: 2019/04/14 17:03:57 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*head;

	if (lst == NULL)
		return (NULL);
	new = f(lst);
	head = new;
	lst = lst->next;
	while (lst != NULL)
	{
		new->next = f(lst);
		new = new->next;
		lst = lst->next;
	}
	return (head);
}
