/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:44:35 by gdalard           #+#    #+#             */
/*   Updated: 2019/04/14 17:20:28 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	int		i;
	int		j;
	char	swap;

	if (!s)
		return (NULL);
	i = ft_strlen(s) - 1;
	j = 0;
	while (j < i)
	{
		swap = s[j];
		s[j++] = s[i];
		s[i--] = swap;
	}
	return (s);
}
