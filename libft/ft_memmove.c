/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:16:19 by gdalard           #+#    #+#             */
/*   Updated: 2019/04/14 17:07:30 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char*)dest;
	s = (char*)src;
	if (d < s)
		while (n--)
			*d++ = *s++;
	else
	{
		d = d + n - 1;
		s = s + n - 1;
		while (n--)
			*d-- = *s--;
	}
	return (dest);
}
