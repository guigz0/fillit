/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouyeme <cmouyeme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 22:54:17 by gdalard           #+#    #+#             */
/*   Updated: 2019/05/10 14:24:45 by gdalard          ###   ########.fr       */
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

void	free_all(char ***tab, int index)
{
	int		lines;

	while (index >= 0)
	{
		lines = 0;
		while (tab[index][lines])
			free(tab[index][lines++]);
		free(tab[index--]);
	}
	free(tab);
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
		if ((tab[i] = treat_tetriminos(buff)))
			if (check(tab[i]))
			{
				i++;
				continue ;
			}
		free_all(tab, i);
		return (NULL);
	}
	if (ret == -1)
		return (NULL);
	return (tab);
}

int		main(int ac, char **av)
{
	int		fd;
	int		nb_tetri;
	char	***tab;
	char	**board;

	board = NULL;
	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	if ((nb_tetri = read_tetriminos(fd)))
	{
		close(fd);
		fd = open(av[1], O_RDONLY);
		if ((tab = chop_tetriminos(fd, nb_tetri)))
		{
			print_tab(tab);
//			set_tetriminos(create_board(board, 4), tab);
			exit(EXIT_SUCCESS);
		}
	}
	ft_putendl("error");
	close(fd);
	return (0);
}
