/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouyeme <cmouyeme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 22:54:17 by gdalard           #+#    #+#             */
/*   Updated: 2019/05/07 18:32:58 by cmouyeme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int		chop_tetriminos(int fd)
{
	char	buff[21 + 1];
	int		ret;
	int		i;
	char	***tab;

	i = 0;
	ret = 0;
	if (!(tab = (char***)malloc(sizeof(char**) * (27))))
		return (0);
	while ((ret = read(fd, buff, 21) && ret != -1))
	{
		buff[21] = '\0';
		if (!(treat_tetriminos(buff, &tab[i])))
			return (0);
		/*while (tab[i])
		{
			while (tab[i][x])
			{
				ft_putendl(tab[i][x]);
				x++;
			}
			ft_putendl("---------");
			i++;
		}*/
		if (!(check(tab[i])))
			return (0);
		i++;
	}
	if (ret == -1)
		return (0);
	tab[i] = 0;
	return (1);
}

int		main(int ac, char **av)
{
	int		fd;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (!read_tetriminos(fd))
	{
		ft_putendl("yoooooooooo");
		ft_putendl("error");
		return (0);
	}
	close(fd);
	fd = open(av[1], O_RDONLY);
	if (!(chop_tetriminos(fd)))
	{
		ft_putendl("yaaaaaaaaaa");
		ft_putendl("error");
		return (0);
	}
	close(fd);
	// printf("check tetriminos : %d\n", (check(tab)));
	//free(tab);
	return (0);
}