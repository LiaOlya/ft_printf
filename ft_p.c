/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <oltkache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:24:31 by oltkache          #+#    #+#             */
/*   Updated: 2018/02/15 16:21:58 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_space_p(int *o, int *s, int l, unsigned long long a)
{
	int f;
	int res;

	res = 0;
	if (o[4] > l + 2)
		f = o[3] - o[4];
	else
		f = o[3] - l - 2;
	if (f > 0 && o[3] > o[4])
	{
		if (o[1] == 1 && o[0] != 1)
		{
			write(1, "0x", 2);
			if (a == 0 && o[4] != -1)
				ft_spaces(f, 1);
			else
				ft_spaces(f, 2);
			res = 1;
		}
		else
			ft_spaces(f, 1);
		*s += f;
	}
	return (res);
}

int		ft_print_p(int i, char *num, unsigned long long a, int *o)
{
	int l;

	l = ft_strlen(num);
	if (a == 0 && o[4] != -1)
		l = 0;
	if (i != 1)
		write(1, "0x", 2);
	if (o[4] != -1)
		if (o[4] > l)
		{
			ft_spaces(o[4] - l, 2);
			l += (o[4] - l);
		}
	if (!(a == 0 && o[4] != -1))
		ft_putstr(num);
	ft_strdel(&num);
	return (l + 2);
}

void	ft_p(char *str, unsigned long long a, int j, int *s)
{
	int		*o;
	int		i;
	int		l;
	char	*num;

	i = -1;
	l = 0;
	o = ft_loop(j, str, 0);
	ft_cast_u(&a, str, 1, str[j]);
	if (o[4] != -1)
		o[1] = 0;
	num = ft_hex(a, &l, 'x');
	if (a == 0 && o[4] != -1)
		l = 0;
	if (o[0] == 1)
		*s += ft_print_p(i, num, a, o);
	i = ft_space_p(o, s, l, a);
	if (o[0] != 1)
		*s += ft_print_p(i, num, a, o);
	ft_memdel((void*)(&o));
}
