/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:31:01 by gdalard           #+#    #+#             */
/*   Updated: 2019/04/25 20:04:01 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	n;

	n = 0;
	if (!(s2 = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (*s1)
		s2[n++] = *s1++;
	s2[n] = '\0';
	return (s2);
}
