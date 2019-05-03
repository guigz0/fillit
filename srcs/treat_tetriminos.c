/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouyeme <cmouyeme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:11:14 by cmouyeme          #+#    #+#             */
/*   Updated: 2019/05/03 17:29:57 by cmouyeme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include "../libft/libft.h"

int		count_used_lines(char *tetri)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (tetri[i])
	{
		if (tetri[i] == '#')
		{
			len++;
			while (tetri[i] != '\n')
				i++;
		}
		i++;
	}
	return (len);
}

char	**treat_tetriminos(char *tetri)
{
	char	**tab;
	int		i;
	int		index;

	if (!(tab = (char**)malloc(sizeof(char *) * (count_used_lines(tetri) + 1))))
		return (NULL);
	i = 0;
	index = 0;
	while (tetri[i])
	{
		if (tetri[i] == '#')
		{
			if (i)
				while ((tetri[i - 1] && tetri[i - 1] != '\n') && tetri[i])
					i--;
			if (!(tab[index++] = ft_strsub(tetri, i, 4)))
				return (NULL);
			i += 4;
		}
		i++;
	}
	tab[count_used_lines(tetri)] = 0;
	return (tab);
}
