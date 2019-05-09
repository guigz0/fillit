/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouyeme <cmouyeme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 22:54:17 by gdalard           #+#    #+#             */
/*   Updated: 2019/05/09 19:30:47 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	free_all(char ***tab, int i)
{
	int		lines;

	while (i >= 0)
	{
		lines = 0;
		while (tab[i][lines])
			free(tab[i][lines++]);
		free(tab[i--]);
	}
	free(tab);
}

int		chop_tetriminos(int fd, int nb_tetri)
{
	char	buff[21 + 1];
	int		ret;
	int		i;
	char	***tab;

	i = 0;
	ret = 0;
	if (!(tab = (char***)malloc(sizeof(char**) * (nb_tetri + 1))))
		return (0);
	while ((ret = read(fd, buff, 21) && ret != -1))
	{
		buff[21] = '\0';
		if (treat_tetriminos(buff, &tab[i]))
			if (check(tab[i]))
			{
				i++;
				continue ;
			}
		free_all(tab, i);
		return (0);
	}
	if (ret == -1)
		return (0);
	tab[i] = 0;
	return (1);
}

int		main(int ac, char **av)
{
	int		fd;
	int		nb_tetri;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (!(nb_tetri = read_tetriminos(fd)))
	{
		ft_putendl("yoooooooooo");
		ft_putendl("error");
		return (0);
	}
	close(fd);
//	printf("nb_tetriminos : %d\n", nb_tetri);
	fd = open(av[1], O_RDONLY);
	if (!(chop_tetriminos(fd, nb_tetri)))
	{
		ft_putendl("yaaaaaaaaaa");
		ft_putendl("error");
		return (0);
	}
	close(fd);
//	printf("check tetriminos : %d\n", (check(tab)));
	return (0);
}
