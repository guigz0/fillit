/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouyeme <cmouyeme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:31:14 by cmouyeme          #+#    #+#             */
/*   Updated: 2019/05/10 14:35:01 by cmouyeme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"

static int	count_used_lines(char *tetri)
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

char		**treat_tetriminos(char *tetri)
{
	int		i;
	int		index;
	char	**tab;

	i = 0;
	index = 0;
	if (!(tab = (char**)malloc(sizeof(char *) * (count_used_lines(tetri) + 1))))
		return (NULL);
	while (tetri[i])
	{
		if (tetri[i] == '#')
		{
			while (i && tetri[i - 1] != '\n' && tetri[i])
				i--;
			if (!(tab[index++] = ft_strsub(tetri, i, 4)))
				return (NULL);
			i += 4;
		}
		i++;
	}
	tab[index] = 0;
	return (tab);
}
