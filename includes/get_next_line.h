/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouyeme <cmouyeme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 22:01:42 by cmouyeme          #+#    #+#             */
/*   Updated: 2019/04/29 18:51:58 by cmouyeme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define BUFF_SIZE 5

int		get_next_line(const int fd, char **line);
char	*read_fd(const int fd, char *str);
int		treat_str(char **str, int i);

#endif
