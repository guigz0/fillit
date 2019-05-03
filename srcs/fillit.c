/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouyeme <cmouyeme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 22:54:17 by gdalard           #+#    #+#             */
/*   Updated: 2019/05/03 18:32:09 by cmouyeme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
// #include <stdio.h>
#include <stdlib.h>

int		chop_tetriminos(int fd, char ***tab)
{
	char	buff[21 + 1];
	int		ret;

	ret = 0;
	while ((ret = read(fd, buff, 21)) > 0)
	{
		buff[21] = '\0';
		if (!(*tab = treat_tetriminos(buff)))
			return (0);
		if (!(check(*tab)))
			return (0);

	}
	if (ret == -1)
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	int		fd;
	char	**tab;
	// int		i = 0;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (!read_tetriminos(fd))
	{
		ft_putendl("error");
		return (0);
	}
	close(fd);
	fd = open(av[1], O_RDONLY);
	chop_tetriminos(fd, &tab);
	// printf("check tetriminos : %d\n", (check(tab)));
	//free(tab);
	return (0);
}