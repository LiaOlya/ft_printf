/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <oltkache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:23:12 by oltkache          #+#    #+#             */
/*   Updated: 2018/02/16 18:09:25 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_sign(int d)
{
	if (d == 1)
		write(1, "-", 1);
	else
		write(1, "+", 1);
}

int		ft_space_d(int y, int z, int m, int x)
{
	if (y > 0)
	{
		if (z == 1 && m != 1 && x == -1)
			ft_spaces(y, 2);
		else
			ft_spaces(y, 1);
		return (1);
	}
	return (0);
}

void	ft_print_d(long long a, int x, int *k)
{
	int p;

	p = ft_num_len(a, 10);
	if (x != -1 && x > p && (*k += x - p))
		ft_spaces(x - p, 2);
	ft_putnbr_long(a);
	*k += ft_num_len(a, 10);
}

void	ft_out_d(long long a, int *k, int *l, int d)
{
	int p;
	int i;

	i = 0;
	if ((l[2] == 1 || d == 1) && (l[1] == 1 || l[0] == 1))
		if (a >= 0 && (i = -1) && (*k += 1))
			ft_sign(d);
	p = ft_num_len(a, 10);
	if (l[0] == 1)
		ft_print_d(a, l[4], k);
	if (l[4] > p)
		p = l[4];
	if (l[2] == 1 || d == 1)
		p += 1;
	l[3] = l[3] - p - l[5];
	if (ft_space_d(l[3], l[1], l[0], l[4]) == 1)
		*k += l[3];
	if ((l[2] == 1 || d == 1) && i != -1 && a >= 0 && (*k += 1))
		ft_sign(d);
	if (l[0] != 1)
		ft_print_d(a, l[4], k);
}

void	ft_d(char *str, long long a, int j, int *k)
{
	int *l;
	int f;
	int d;

	f = 0;
	if (str[j] == 'D')
		f = 1;
	l = ft_loop(j, str, 0);
	d = ft_cast(&a, str, f);
	if (l[5] == 1 && d == 0 && (l[4] >= l[3] || l[4] == -1))
	{
		if (l[2] == 0 && (*k += 1))
			write(1, " ", 1);
	}
	else
		l[5] = 0;
	if (ft_h_d(a, l, d, k) == 1)
		return ;
	ft_out_d(a, k, l, d);
	ft_memdel((void*)(&l));
}
