/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:36:49 by gdalard           #+#    #+#             */
/*   Updated: 2019/05/11 22:07:19 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "fillit.h"

char	**reset_tetriminos(char **board, int k)
{
	int		i;
	int		j;

	i = 0;
	while (board[i])
	{
		j = 0;
		while (board[i][j])
		{
			if (board[i][j] == k + 'A')
				board[i][j] = '.';
			j++;
		}
		i++;
	}
	return (board);
}

int		can_set_tetriminos(char **board, char **tab, t_pos pos)
{
	int		i;
	int		j;
	int		sj;

	i = -1;
	sj = 100;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == '#')
			{
				if (sj != 100 && (!board[pos.x + i]
						|| board[pos.x + i][j - sj] != '.'))
					return (0);
				if (sj == 100 && board[pos.x][pos.y] != '.')
					return (0);
				else if (sj == 100)
					sj = j - pos.y;
			}
		}
	}
	return (1);
}

char	**set_tetriminos(char **board, char **tab, t_pos pos, int k)
{
	int		i;
	int		j;
	int		sj;

	i = -1;
	sj = 100;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == '#')
			{
				if (sj == 100)
				{
					board[pos.x][pos.y] = k + 'A';
					sj = j - pos.y;
				}
				else
					board[pos.x + i][j - sj] = k + 'A';
			}
		}
	}
	return (board);
}

int		fillit(char **board, char ***tab, int i, int nb_tetri)
{
	t_pos	pos;

	pos.x = 0;
	if (i == nb_tetri)
		return (1);
	while (board[pos.x])
	{
		pos.y = 0;
		while (board[pos.x][pos.y])
		{
			if (can_set_tetriminos(board, tab[i], pos))
			{
				board = set_tetriminos(board, tab[i], pos, i);
				if (fillit(board, tab, i + 1, nb_tetri))
					return (1);
				board = reset_tetriminos(board, i);
			}
			pos.y++;
		}
		pos.x++;
	}
	return (0);
}

char	**create_board(char **board, int size)
{
	int		n;
	int		y;

	n = 0;
	y = 0;
	if (board)
	{
		while (board[n])
			free(board[n++]);
		free(board);
	}
	n = 0;
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
