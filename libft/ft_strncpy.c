/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:12:36 by gdalard           #+#    #+#             */
/*   Updated: 2019/04/15 18:33:49 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	j;
	size_t	size;

	j = 0;
	size = 0;
	while (src[j] && j++ < n)
		size++;
	if (size != n)
		ft_memset(dest + size, '\0', n - size);
	return (ft_memcpy(dest, src, size));
}
