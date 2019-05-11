/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouyeme <cmouyeme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 22:54:17 by gdalard           #+#    #+#             */
/*   Updated: 2019/05/11 22:07:22 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

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

int		min_n(int nb_tetri)
{
	int		n;
	int		min_block;

	n = 2;
	min_block = nb_tetri * 4;
	while (n * n < min_block)
		n++;
	return (n);
}

void	do_fillit(char **board, char ***tab, int nb_tetri)
{
	int		n;

	n = min_n(nb_tetri);
	board = create_board(board, n);
	while (!fillit(board, tab, 0, nb_tetri))
		board = create_board(board, ++n);
	n = 0;
	while (board[n])
		ft_putendl(board[n++]);
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
			do_fillit(board, tab, nb_tetri);
			close(fd);
			exit(EXIT_SUCCESS);
		}
	}
	ft_putendl("error");
	close(fd);
	return (0);
}
