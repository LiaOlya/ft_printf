/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <oltkache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:27:06 by oltkache          #+#    #+#             */
/*   Updated: 2018/02/16 16:08:07 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		*ft_intnew(int size)
{
	int i;
	int *new;

	i = 0;
	new = (int *)malloc(sizeof(int) * size);
	while (i < size)
		new[i++] = 0;
	return (new);
}

int		ft_ch(int c)
{
	if (c == 1 && MB_CUR_MAX > 1)
		return (1);
	if (c == 0)
		return (1);
	return (0);
}

void	ft_ch_loop(int **res, int p, char *str, int c)
{
	int i;

	i = 0;
	while (p > 0)
	{
		if (str[i] == '-')
			(*res)[0] = ft_increm_1(&p, &i);
		else if (str[i] == 'l' && ft_ch(c) == 1)
			(*res)[7] = ft_increm_1(&p, &i);
		else if (str[i] == '#')
			(*res)[6] = ft_increm_1(&p, &i);
		else if (str[i] == '0')
			(*res)[1] = ft_increm_1(&p, &i);
		else if (str[i] == '+')
			(*res)[2] = ft_increm_1(&p, &i);
		else if (ft_isdigit(str[i]) && (*res)[3] == 0)
			(*res)[3] = ft_increm_2(&str[i], &p, &i, 1);
		else if (str[i] == '.')
			(*res)[4] = ft_increm_2(&str[i + 1], &p, &i, 2);
		else if (str[i] == ' ')
			(*res)[5] = ft_increm_1(&p, &i);
		else
			ft_increm_1(&p, &i);
	}
}

int		*ft_loop(int p, char *str, int c)
{
	int *res;
	int i;

	res = ft_intnew(8);
	i = 0;
	res[4] = -1;
	ft_ch_loop(&res, p, str, c);
	return (res);
}
