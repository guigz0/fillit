/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouyeme <cmouyeme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:11:14 by cmouyeme          #+#    #+#             */
/*   Updated: 2019/05/03 17:02:37 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"
/*
int		count_charofline(char *tetri, int i)
{
	int		size_line;

	size_line = 0;
	while (tetri[i] == '#')
	{
		i++;
		size_line++;
	}
	return (size_line);
}
*/
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
			while (i && tetri[i - 1] != '\n' && tetri[i])
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
/*
char	**treat_tetriminos(char *tetri)
{
	char	**tab;
	int		i;
	int		index;
//	int		size_line;


	if (!(tab = (char**)malloc(sizeof(char *) * (count_used_lines(tetri) + 1))))
		return (NULL);
	i = 0;
	index = 0;
	while (tetri[i])
	{
		if (tetri[i] == '#')
		{
//			size_line = count_charofline(tetri, i);
			if (i)
				while (tetri[i - 1] != '\n' && tetri[i])
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

int		main(int argc, char **argv)
{
	int		fd;
	char	tetri[21 + 1];
	int		ret;
	int		i;
	char	**result;

	fd = 0;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (0);
	i = 0;
	ret = read(fd, tetri, 21);
	tetri[21] = '\0';
	result = treat_tetriminos(tetri);
	while (result[i])
	{
		ft_putchar('[');
		ft_putstr(result[i]);
		ft_putchar(']');
		ft_putstr("\n---------------\n");
		ft_putchar('\n');
		ft_strdel(&result[i]);
		i++;
	}
	free(result);
	close(fd);
	return (0);
}*/
