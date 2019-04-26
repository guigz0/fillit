/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:23:31 by gdalard           #+#    #+#             */
/*   Updated: 2019/04/14 17:04:25 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstrev(t_list *lst)
{
	t_list	*tmp;
	t_list	*head;

	head = NULL;
	while (lst != NULL)
	{
		tmp = lst;
		lst = lst->next;
		ft_lstadd(&head, tmp);
	}
	return (head);
}
