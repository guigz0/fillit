/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouyeme <cmouyeme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 23:09:16 by gdalard           #+#    #+#             */
/*   Updated: 2019/05/09 18:05:11 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

int		read_tetriminos(int fd);
int		treat_tetriminos(char *tetri, char ***tab);
int		check(char **block);
int		chop_tetriminos(int fd, int nb_tetri);

#endif
