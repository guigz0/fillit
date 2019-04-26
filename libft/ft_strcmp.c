/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:29:16 by gdalard           #+#    #+#             */
/*   Updated: 2019/04/14 17:12:18 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	ss1;
	unsigned char	ss2;

	ss1 = (unsigned char)*s1;
	ss2 = (unsigned char)*s2;
	while (ss1 == ss2)
	{
		if (!ss1 || !ss2)
			return (0);
		ss1 = (unsigned char)*++s1;
		ss2 = (unsigned char)*++s2;
	}
	return (ss1 - ss2);
}
