/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 23:12:10 by gdalard           #+#    #+#             */
/*   Updated: 2019/04/14 17:18:01 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	len;
	char	*s;
	size_t	i;

	i = 0;
	len = 0;
	while (s2[i] && i++ < n)
		len++;
	s = s1;
	s1 += ft_strlen(s1);
	s1[len] = 0;
	ft_memcpy(s1, s2, len);
	return (s);
}
