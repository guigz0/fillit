/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 20:11:13 by gdalard           #+#    #+#             */
/*   Updated: 2019/04/14 17:18:21 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	ss1;
	unsigned char	ss2;

	ss1 = (unsigned char)*s1;
	ss2 = (unsigned char)*s2;
	if (n == 0)
		return (0);
	while (ss1 == ss2 && --n)
	{
		if (!ss1 || !ss2)
			return (0);
		ss1 = (unsigned char)*++s1;
		ss2 = (unsigned char)*++s2;
	}
	return (ss1 - ss2);
}
