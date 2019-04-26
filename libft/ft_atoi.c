/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdalard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:30:06 by gdalard           #+#    #+#             */
/*   Updated: 2019/04/14 17:00:13 by gdalard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		is_positive;
	int		result;

	result = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	is_positive = *str == '-' ? -1 : 1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	return (result * is_positive);
}
