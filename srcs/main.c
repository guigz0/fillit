/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouyeme <cmouyeme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 22:54:17 by gdalard           #+#    #+#             */
/*   Updated: 2019/05/14 21:54:02 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

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

void	do_fillit(char ***tab, int nb_tetri)
{
	char	**board;
	int		n;

	board = NULL;
	n = min_n(nb_tetri);
	board = create_board(board, n);
	while (!fillit(board, tab, 0, nb_tetri))
		board = create_board(board, ++n);
	n = 0;
	while (board[n])
		ft_putendl(board[n++]);
	n = 0;
	while (board[n])
		free(board[n++]);
	free(board);
}

int		main(int ac, char **av)
{
	int		fd;
	int		nb_tetri;
	char	***tab;

	if (ac != 2)
	{
		write(1, "usage: ./fillit path_of_file\n", 29);
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if ((nb_tetri = read_tetriminos(fd)))
	{
		close(fd);
		fd = open(av[1], O_RDONLY);
		if ((tab = chop_tetriminos(fd, nb_tetri)))
		{
			do_fillit(tab, nb_tetri);
			close(fd);
			exit(EXIT_SUCCESS);
		}
	}
	ft_putendl("error");
	close(fd);
	return (0);
}
