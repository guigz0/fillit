/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouyeme <cmouyeme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:11:14 by cmouyeme          #+#    #+#             */
/*   Updated: 2019/05/09 19:30:33 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
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

int			treat_tetriminos(char *tetri, char ***tab)
{
	int		i;
	int		index;
	char	**result;

	i = 0;
	index = 0;
	*tab = NULL;
	if (!(result = (char**)malloc(sizeof(char *) * (count_used_lines(tetri) + 1))))
		return (0);
	while (tetri[i])
	{
		if (tetri[i] == '#')
		{
			if (i)
				while ((tetri[i - 1] && tetri[i - 1] != '\n') && tetri[i])
					i--;
			if (!(result[index++] = ft_strsub(tetri, i, 4)))
				return (0);
			i += 4;
		}
		i++;
	}
	result[index] = 0;
	*tab = result;
	return (1);
}
