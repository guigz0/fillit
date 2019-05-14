/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:54:54 by gdalard           #+#    #+#             */
/*   Updated: 2019/05/14 21:08:12 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		calc_adjacent_hash(char *block, int x, int y)
{
	int		nb;

	nb = 0;
	if (y && block[x + y - 1] == '#')
		nb++;
	if (x + y + 1 < 20 && block[x + y + 1] == '#')
		nb++;
	if (x && block[x - 5 + y] == '#')
		nb++;
	if (x + y + 5 < 20 && block[x + 5 + y] == '#')
		nb++;
	return (nb);
}

int		check(char *block)
{
	int		link;
	int		x;
	int		y;

	link = 0;
	x = 0;
	y = 0;
	while (x + y < 20)
	{
		if (y % 5 == 4)
		{
			x += 5;
			y = 0;
		}
		if (block[x + y] == '#')
			link += calc_adjacent_hash(block, x, y);
		y++;
	}
	if (link == 6 || link == 8)
		return (1);
	return (0);
}
