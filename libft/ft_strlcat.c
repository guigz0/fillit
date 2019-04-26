/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 23:44:36 by gdalard           #+#    #+#             */
/*   Updated: 2019/04/14 17:16:22 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	if (i >= size)
		return (size + j);
	j += i;
	while (*src && i < size - 1)
		dst[i++] = *src++;
	dst[i] = 0;
	return (j);
}
