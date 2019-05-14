/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouyeme <cmouyeme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:31:14 by cmouyeme          #+#    #+#             */
/*   Updated: 2019/05/14 21:09:35 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <unistd.h>
#include <stdlib.h>

void	free_all(char ***tab)
{
	int		lines;
	int		index;

	index = 0;
	while (tab[index])
	{
		lines = 0;
		while (tab[index][lines])
			free(tab[index][lines++]);
		free(tab[index++]);
	}
	free(tab);
}

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

char	***chop_tetriminos(int fd, int nb_tetri)
{
	char	buff[21 + 1];
	int		ret;
	int		i;
	char	***tab;

	i = 0;
	ret = 0;
	if (!(tab = (char***)malloc(sizeof(char**) * (nb_tetri + 1))))
		return (NULL);
	tab[nb_tetri] = 0;
	while ((ret = read(fd, buff, 21) && ret != -1))
	{
		buff[21] = '\0';
		tab[i] = NULL;
		if ((check(buff)))
			if ((tab[i++] = treat_tetriminos(buff)))
				continue ;
		free_all(tab);
		return (NULL);
	}
	if (ret == -1)
		return (NULL);
	return (tab);
}
