/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <oltkache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:24:10 by oltkache          #+#    #+#             */
/*   Updated: 2018/02/14 17:03:14 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	unsigned long long	i[3];

	i[0] = 0;
	i[2] = 0;
	i[1] = 1;
	while (ft_isspace(str[i[0]]) != 0 && str[i[0]] != '-')
		++i[0];
	if (str[i[0]] == '-' || str[i[0]] == '+')
	{
		if (str[i[0]] == '-')
			i[1] = -1;
		++i[0];
	}
	while (str[i[0]] && ft_isdigit(str[i[0]]))
	{
		i[2] += (str[i[0]] - '0');
		if (ft_isdigit(str[i[0] + 1]))
			i[2] *= 10;
		++i[0];
	}
	if (i[2] > 9223372036854775807 && i[1] == (unsigned long long)(-1))
		return (0);
	if (i[2] >= 9223372036854775807)
		return (-1);
	return ((int)(i[2] * (int)i[1]));
}
