/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:55:16 by gdalard           #+#    #+#             */
/*   Updated: 2019/04/25 20:00:23 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*d;
	size_t	n;

	if (!s1 || !s2)
		return (NULL);
	n = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(d = (char*)malloc(sizeof(char) * n)))
		return (NULL);
	n = 0;
	while (*s1)
		d[n++] = *s1++;
	while (*s2)
		d[n++] = *s2++;
	d[n] = '\0';
	return (d);
}
