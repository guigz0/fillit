/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:03:37 by gdalard           #+#    #+#             */
/*   Updated: 2019/04/14 17:20:53 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_words(const char *s, char c)
{
	int		n;
	int		k;

	n = 0;
	k = 0;
	while (*s)
	{
		if (*s != c)
			k++;
		else
			k = 0;
		if (k == 1)
			n++;
		s++;
	}
	return (n);
}

static int	ft_filltab(char **tab, const char *s, char c)
{
	int		n;
	int		i;

	n = 0;
	i = 0;
	while (*s)
	{
		while (s[n] && s[n] != c)
			n++;
		if (n != 0)
		{
			if (!(tab[i] = ft_strsub(s, 0, n)))
			{
				while (i >= 0)
					free(tab[i--]);
				return (-1);
			}
			i++;
			s += n - 1;
			n = 0;
		}
		s++;
	}
	return (0);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		n;

	if (!s || !c)
		return (NULL);
	n = ft_words(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (n + 1))))
		return (NULL);
	tab[n] = 0;
	if (ft_filltab(tab, s, c) == -1)
	{
		free(tab);
		return (NULL);
	}
	return (tab);
}
