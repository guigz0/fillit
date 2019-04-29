/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_blocks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouyeme <cmouyeme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 22:55:27 by cmouyeme          #+#    #+#             */
/*   Updated: 2019/04/29 18:52:08 by cmouyeme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"
#include <unistd.h>

char	*read_tetriminos(int fd)
{
	// char	*str = NULL;
	int		ret;
	char	buff[BUFF_SIZE + 1];

	ret = 0;
	while ((ret = read(fd, buff, BUFF_SIZE) > 0) && (ret != -1))
	{
		buff[ret] = '\0';
		if (!str)
			ft_strnew(0);

	}
}

int		analyse_tetriminos(char *str)
{
	int		i;
	char	*line;
	

}