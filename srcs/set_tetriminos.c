/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:36:49 by gdalard           #+#    #+#             */
/*   Updated: 2019/05/10 17:42:25 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	print_board(char **board)
{
	int		n;

	n = 0;
	while (board[n])
		printf("->%s\n", board[n++]);
	printf("---------\n");
}

char	**reset_tetriminos(char **board)
{
	int		i;
	int		j;

	i = 0;
	while (board[i])
	{
		j = 0;
		while (board[i][j])
		{
			if (board[i][j] == 'A')
				board[i][j] = '.';
			j++;
		}
		i++;
	}
	return (board);
}

/*void	set_tetriminos(char	**board, char **tab, int  x, int y)
{
	int		i;
	int		j;
	int		sj;

	i = -1;
	sj = 100;
	while (tab[0][++i])
	{
		j = -1;
		while (tab[0][i][++j])
		{
			if (tab[0][i][j] == '#')
			{
				if (sj != 100 && board[x + i][j - sj] == '.')
					board[x + i][j - sj] = 'A';
				else if (sj != 100)
				{
					if (!board[x][y])
						set_tetriminos(reset_tetriminos(board), tab, x + 1, 0);
					set_tetriminos(reset_tetriminos(board), tab, x, y + 1);
				}
				if (sj == 100 && board[x][y] == '.')
				{
					board[x][y] = 'A';
					sj = j - y;
				}
			}
		}
	}
}*/


void	set_tetriminos(char	**board, char **tab, int  x, int y)
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
				if (sj != 100 && board[x + i][j - sj] == '.')
					board[x + i][j - sj] = 'A';
				else if (sj != 100)
				{
					if (!board[x][y])
						set_tetriminos(reset_tetriminos(board), tab, x + 1, 0);
					set_tetriminos(reset_tetriminos(board), tab, x, y + 1);
				}
				if (sj == 100 && board[x][y] == '.')
				{
					board[x][y] = 'A';
					sj = j - y;
				}
			}
		}
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
