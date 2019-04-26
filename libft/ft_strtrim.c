/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:26:38 by gdalard           #+#    #+#             */
/*   Updated: 2019/04/14 17:22:07 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*d;
	int		n;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	n = ft_strlen(s) - 1;
	while ((s[n] == '\t' || s[n] == '\n' || s[n] == ' ') && n > 0)
		n--;
	while ((*s == '\t' || *s == '\n' || *s == ' ') && *s++)
		i++;
	if (n != 0)
		n = n - i + 1;
	if (!(d = ft_memalloc(n + 1)))
		return (NULL);
	i = 0;
	while (i < n)
		d[i++] = *s++;
	return (d);
}
