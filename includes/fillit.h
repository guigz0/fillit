/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouyeme <cmouyeme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 23:09:16 by gdalard           #+#    #+#             */
/*   Updated: 2019/05/14 20:35:11 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

int				read_tetriminos(int fd);
char			***chop_tetriminos(int fd, int nb_tetri);
int				check(char *block);
char			**create_board(char **board, int size);
int				fillit(char **board, char ***tab, int i, int nb_tetri);

typedef struct	s_pos
{
	int	x;
	int	y;
}				t_pos;

#endif
