/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:15:23 by gdalard           #+#    #+#             */
/*   Updated: 2019/04/14 17:17:21 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		d[i] = f(d[i]);
		i++;
	}
	return (d);
}
