/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:27:28 by gdalard           #+#    #+#             */
/*   Updated: 2019/04/14 17:04:55 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*zone;

	zone = (void*)malloc(sizeof(void) * size);
	if (zone == NULL)
		return (NULL);
	ft_bzero(zone, size);
	return (zone);
}
