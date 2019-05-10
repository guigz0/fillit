/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:36:49 by gdalard           #+#    #+#             */
/*   Updated: 2019/05/10 16:26:18 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	set_tetriminos(char	**board, char ***tab)
{
	int		x;
	int		y;
	int		i;
	int		j;
	int		sj;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	sj = 100;
	while (tab[0][i])
	{
		while (tab[0][i][j])
		{
			if (tab[0][i][j] == '#')
			{
				if (sj != 100 && board[x][y] == '.')
					board[x + i][j - sj] = 'A';
				if (sj == 100 && board[x][y] == '.')
				{
					board[x][y] = 'A';
					sj = j - y;
				}
			}
			j++;
		}
		i++;
		j = 0;
	}
}

char	**create_board(char **board, int size)
{
	int		n;
	int		y;

	n = 0;
	y = 0;
	if (!(board = (char**)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	board[size] = 0;
	while (n < size)
	{
		if (!(board[n] = (char*)malloc(sizeof(char) * size + 1)))
			return (NULL);
		while (y < size)
			board[n][y++] = '.';
		y = 0;
		board[n++][size] = '\0';
	}
	return (board);
}
