/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:36:49 by gdalard           #+#    #+#             */
/*   Updated: 2019/05/10 12:51:57 by gdalard          ###   ########.fr       */
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
