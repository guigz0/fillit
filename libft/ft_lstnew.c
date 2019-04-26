/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:07:19 by gdalard           #+#    #+#             */
/*   Updated: 2019/04/14 17:04:12 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*lst;

	if (!(lst = (t_list*)malloc(sizeof(*lst))))
		return (NULL);
	lst->content_size = (void*)content == NULL ? 0 : content_size;
	if (!(lst->content = (void*)malloc(sizeof(content_size))))
	{
		free(lst);
		return (NULL);
	}
	if ((void*)content != NULL)
		lst->content = ft_memcpy(lst->content, content, content_size);
	else
		lst->content = NULL;
	lst->next = NULL;
	return (lst);
}
