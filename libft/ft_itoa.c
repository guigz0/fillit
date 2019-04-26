/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:28:31 by gdalard           #+#    #+#             */
/*   Updated: 2019/04/14 17:01:27 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	return (n = n < 0 ? -n : n);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		k;
	int		size;

	k = n;
	size = k < 0 ? 2 : 1;
	while (k >= 10 || k <= -10)
	{
		k /= 10;
		size++;
	}
	if (!(s = ft_memalloc(size + 1)))
		return (NULL);
	k = 0;
	if (n < 0)
		s[k++] = '-';
	while (size-- > k)
	{
		s[size] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (s);
}
