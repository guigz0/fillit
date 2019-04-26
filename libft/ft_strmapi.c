/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:33:13 by gdalard           #+#    #+#             */
/*   Updated: 2019/04/14 17:17:46 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f) (unsigned int, char))
{
	int		i;
	int		j;
	char	*d;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	if ((d = ft_strnew(j)) == NULL)
		return (NULL);
	d = ft_strcpy(d, s);
	while (i < j)
	{
		d[i] = f(i, d[i]);
		i++;
	}
	return (d);
}
