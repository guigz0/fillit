/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:36:28 by gdalard           #+#    #+#             */
/*   Updated: 2019/05/07 18:37:43 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	set_tetriminos(char	**board, char ***tab)
{
	
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

int		main(int ac, char **av)
{
	char	**board = NULL;
	int		n = 0;

	if (ac != 2 || atoi(av[1]) < 2)
		return (0);
	board = create_board(board, atoi(av[1]));
	while (board[n])
		printf("%s\n", board[n++]);
	set_tetriminos(board);
	return (0);
}
