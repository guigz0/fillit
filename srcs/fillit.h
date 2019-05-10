/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouyeme <cmouyeme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 23:09:16 by gdalard           #+#    #+#             */
/*   Updated: 2019/05/10 13:46:09 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

int		read_tetriminos(int fd);
char	**treat_tetriminos(char *tetri);
int		check(char **block);
char	***chop_tetriminos(int fd, int nb_tetri);
char	**create_board(char **board, int size);
void	set_tetriminos(char **board, char ***tab);

#endif
