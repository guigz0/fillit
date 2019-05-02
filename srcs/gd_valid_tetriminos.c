/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gd_valid_tetriminos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:54:54 by gdalard           #+#    #+#             */
/*   Updated: 2019/05/02 22:42:27 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		check(char block[3][5])
{
	int		stick;
	int		x;
	int		y;

	stick = 0;
	x = 0;
	y = 0;
	while (x < 2)
	{
		printf("block[x] : %s\n", block[x]);
		while (y < 3 && stick < 3)
		{
			if (block[x][y] == '#')
			{
				if (block[x][y + 1] == '#')
					stick++;
				else if (block[x + 1][y] == '#')
					stick++;
			}
			y++;
		}
		x++;
		y = 0;
	}
	return (stick);
}

int		main(void)
{
	char block[3][5] = 
	{{ '.' , '#' , '.' , '.' , '\0'},
	{ '#' , '#' , '#' , '.' , '\0'},
	{ '\0' , '\0' , '\0' , '\0' , '\0'}};
	printf("%d\n", check(block));
	return (0);
}
