/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 22:54:17 by gdalard           #+#    #+#             */
/*   Updated: 2019/05/03 17:15:15 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "fillit.h"
#include "libft.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int		fd;
	char	**tab;
	char	buff[21 + 1];
	int		i = 0;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (!read_tetriminos(fd))
	{
		ft_putendl("error");
		exit(
	}
	ft_putendl("first check OK");
	close(fd);
	fd = open(av[1], O_RDONLY);
	while (read(fd, buff, 21))
	{
	//	printf("YOLO\n");
		buff[21] = '\0';
		tab = treat_tetriminos(buff);
		while (tab[i])
			printf("%s\n", tab[i++]);
		i = 0;
		printf("check tetriminos : %d\n", (check(tab)));
	}
	return (0);
}
