/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:38:34 by gdalard           #+#    #+#             */
/*   Updated: 2019/04/16 15:08:16 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char			*d;
	unsigned int	n;

	if (!s)
		return (NULL);
	n = 0;
	if (!(d = ft_memalloc(len + 1)))
		return (NULL);
	while (n < len)
		d[n++] = s[start++];
	d[n] = 0;
	return (d);
}
