/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouyeme <cmouyeme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:15:14 by cmouyeme          #+#    #+#             */
/*   Updated: 2019/05/14 19:03:53 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		treat_str(char **str, int i)
{
	char	*tmp;

	if (!(tmp = ft_strsub(*str, i + 1, (ft_strlen(*str) - i))))
		return (-1);
	ft_strdel(&(*str));
	*str = tmp;
	return (1);
}

char	*read_fd(const int fd, char *str)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	char			*tmp;

	if (str == NULL)
		if ((str = ft_strnew(0)) == NULL)
		{
			ft_strdel(&str);
			return (NULL);
		}
	ret = 0;
	while (!ft_strchr(str, '\n') && ((ret = read(fd, buf, BUFF_SIZE))
			&& ret != -1))
	{
		tmp = str;
		buf[ret] = '\0';
		if ((str = ft_strjoin(str, buf)) == NULL)
			return (NULL);
		ft_strdel(&tmp);
	}
	if (ret == -1)
		return (NULL);
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	int				i;
	static char		*tab[OPEN_MAX + 1];

	if (fd < 0 || fd > OPEN_MAX || line == NULL || BUFF_SIZE < 1
		|| ((tab[fd] = read_fd(fd, tab[fd])) == NULL))
		return (-1);
	i = 0;
	if (tab[fd][i])
	{
		while (tab[fd][i] && tab[fd][i] != '\n')
			i++;
		if (!(*line = ft_strsub(tab[fd], 0, i)))
		{
			ft_strdel(&tab[fd]);
			return (-1);
		}
		return (treat_str(&tab[fd], i));
	}
	return (0);
}
