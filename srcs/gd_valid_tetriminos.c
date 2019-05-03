/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gd_valid_tetriminos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:54:54 by gdalard           #+#    #+#             */
/*   Updated: 2019/05/03 17:05:56 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		hash_around(char **block, int x, int y)
{
	int		nb;

	nb = 0;
	if (y && block[x][y - 1] == '#')
		nb++;
	if (block[x][y + 1] && block[x][y + 1] == '#')
		nb++;
	if (x && block[x - 1][y] == '#')
		nb++;
	if (block[x + 1] && block[x + 1][y] == '#')
		nb++;
	return (nb);
}

int		check(char **block)
{
	int		link;
	int		x;
	int		y;

	link = 0;
	x = -1;
	while (block[++x])
	{
		y = -1;
		while (++y < 4)
			if (block[x][y] == '#')
				link += hash_around(block, x, y);
	}
	if (link == 6 || link == 8)
		return (1);
	return (0);
}
