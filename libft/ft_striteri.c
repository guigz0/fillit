/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:03:21 by gdalard           #+#    #+#             */
/*   Updated: 2019/04/14 17:14:46 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	n;
	unsigned int	i;

	if (!s || !f)
		return ;
	n = ft_strlen(s);
	i = 0;
	while (i < n)
	{
		f(i++, s++);
	}
}
