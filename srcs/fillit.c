/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouyeme <cmouyeme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 22:54:17 by gdalard           #+#    #+#             */
/*   Updated: 2019/05/09 21:57:28 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	print_tab(char ***tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
			ft_putendl(tab[i][j++]);
		if (tab[i + 1])
			ft_putchar('\n');
		i++;
	}
}

void	free_all(char ***tab)
{
	int		index;
	int		lines;

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

char	***chop_tetriminos(char ***tab, int fd, int nb_tetri)
{
	char	buff[21 + 1];
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	if (!(tab = (char***)malloc(sizeof(char**) * (nb_tetri + 1))))
		return (NULL);
	while ((ret = read(fd, buff, 21) && ret != -1))
	{
		buff[21] = '\0';
		if ((tab[i] = treat_tetriminos(buff)))
			if (check(tab[i++]))
				continue ;
		free_all(tab);
		return (NULL);
	}
	if (ret == -1)
		return (NULL);
	tab[i] = 0;
	return (tab);
}

int		main(int ac, char **av)
{
	int		fd;
	int		nb_tetri;
	char	***tab;

	tab = NULL;
	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	if ((nb_tetri = read_tetriminos(fd)))
	{
		close(fd);
		fd = open(av[1], O_RDONLY);
		if ((tab = chop_tetriminos(tab, fd, nb_tetri)))
		{
			print_tab(tab);
			exit(EXIT_SUCCESS);
		}
	}
	ft_putendl("error");
	close(fd);
	return (0);
}
