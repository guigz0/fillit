/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouyeme <cmouyeme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 22:55:27 by cmouyeme          #+#    #+#             */
/*   Updated: 2019/05/14 19:41:48 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int	calc_nb_tetriminos(int nb_lines)
{
	int		nb_tetri;
	int		nb_linebreak;
	int		result;

	nb_tetri = 1;
	nb_linebreak = 0;
	result = 0;
	while (result != nb_lines)
		result = nb_tetri++ * 4 + nb_linebreak++;
	return (--nb_tetri);
}

int			read_tetriminos(int fd)
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
	return (nb_hash == 4 ? calc_nb_tetriminos(nb_lines) : 0);
}
