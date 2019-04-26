/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:00:09 by gdalard           #+#    #+#             */
/*   Updated: 2019/04/14 17:02:54 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*current;
	t_list	*nxt;

	if (!alst || !*alst)
		return ;
	current = *alst;
	while (current != NULL)
	{
		nxt = current->next;
		ft_lstdelone(&current, del);
		current = nxt;
	}
	*alst = NULL;
}
