/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gd_read_blocks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouyeme <cmouyeme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 22:55:27 by cmouyeme          #+#    #+#             */
/*   Updated: 2019/05/02 23:13:08 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "get_next_line.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>
//#include <fcntl.h>

int		read_tetriminos(int fd)
{
	int		nb_hash;
	int		i;
	int		nb_lines;
	char	*line;

	nb_lines = 0;
	while ((i = get_next_line(fd, &line)) > 0 && ++nb_lines)
	{
		i = 0;
		nb_hash = (nb_lines % 5) == 1 ? 0 : nb_hash;
		while (line[i])
		{
			if (!(nb_lines % 5) || i > 3 || (line[i] != '.' && line[i] != '#'))
				ft_strdel(&line);
			if (line == NULL)
				return (0);
			nb_hash = line[i++] == '#' ? ++nb_hash : nb_hash;
		}
		ft_strdel(&line);
		if ((!(nb_lines % 5) && nb_hash != 4) || (nb_lines % 5 && i < 4))
			return (0);
	}
	if (i == -1 || !(nb_lines % 5) || nb_lines < 4 || nb_lines > 129)
		return (0);
	return (nb_hash == 4 ? 1 : 0);
}
/*
int		main(int ac, char **av)
{
	int		fd;

	if (ac != 2)
	{
		ft_putendl("error");
		exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	printf("%d\n", read_tetriminos(fd));
	close(fd);
	return (0);
}*/