/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouyeme <cmouyeme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 23:09:16 by gdalard           #+#    #+#             */
/*   Updated: 2019/05/03 18:27:24 by cmouyeme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

int		read_tetriminos(int fd);
char	**treat_tetriminos(char *tetri);
int		check(char **block);
int		chop_tetriminos(int fd, char ***tab);

#endif
