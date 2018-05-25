/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <oltkache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:23:19 by oltkache          #+#    #+#             */
/*   Updated: 2018/02/15 13:11:18 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_u(int x, unsigned long long a, int *k)
{
	int len;

	len = ft_num_len_u(a, 10);
	if (x > len && (*k += x - len))
		ft_spaces(x - len, 2);
	ft_putnbr_long_u(a);
	*k += len;
}

void	ft_space_u(int *l, int *k, unsigned long long a)
{
	int p;

	p = ft_num_len_u(a, 10);
	if (l[4] > p)
		p = l[4];
	if (l[3] != 0)
	{
		if (l[1] == 1 && l[0] != 1 && (l[4] == 0 || l[4] == -1))
			ft_spaces(l[3] - p, 2);
		else
			ft_spaces(l[3] - p, 1);
		if (l[3] - p > 0)
			*k += (l[3] - p);
	}
}

void	ft_u(char *str, unsigned long long a, int j, int *k)
{
	int *l;
	int c;

	c = 0;
	if (str[j] == 'U')
		c = 1;
	l = ft_loop(j, str, 0);
	ft_cast_u(&a, str, c, str[j]);
	if ((a == 0 && l[4] == 0))
	{
		ft_spaces(l[3], 1);
		*k += l[3];
		return ;
	}
	if (l[0] == 1)
		ft_print_u(l[4], a, k);
	ft_space_u(l, k, a);
	if (l[0] != 1)
		ft_print_u(l[4], a, k);
	ft_memdel((void*)(&l));
}
