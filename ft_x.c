/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <oltkache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:23:37 by oltkache          #+#    #+#             */
/*   Updated: 2018/02/16 17:18:17 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	ft_hex_ch(int b, int a, char h, int ch)
{
	int c;

	if (h == 'x')
		c = 39;
	if (h == 'X')
		c = 7;
	if (b < 10 && ch == 0)
		return (b + '0');
	else if (ch == 0)
		return (b + c + '0');
	if (ch == 1)
		return (a + c + '0');
	return (0);
}

void	ft_hash(char str)
{
	if (str == 'X')
		write(1, "0X", 2);
	if (str == 'x')
		write(1, "0x", 2);
}

int		ft_space_x(int *o, int l, char str, unsigned long long a)
{
	int f;

	if (o[4] > l)
		f = o[3] - o[4];
	else
		f = o[3] - l;
	if (f > 0 && o[3] > o[4])
	{
		if (o[1] == 1 && o[0] != 1)
		{
			if (o[6] == 1)
				ft_hash(str);
			if (o[6] != -1)
			{
				if (a == 0 && o[4] != -1)
					ft_spaces(f, 1);
				else
					ft_spaces(f, 2);
			}
		}
		else
			ft_spaces(f, 1);
		return (f);
	}
	return (0);
}

int		ft_print_x(int *o, char *num, unsigned long long a, char str)
{
	int l;

	l = ft_strlen(num);
	if (o[6] == 1)
		l += 2;
	if (a == 0 && o[4] != -1)
		l = 0;
	if ((o[0] == 1 && o[6] == 1) || (o[0] != 1 && o[6] == 1 && o[1] != 1))
		ft_hash(str);
	if (o[4] != -1)
		if (o[4] > l && o[6] != -1)
		{
			ft_spaces(o[4] - l, 2);
			l += (o[4] - l);
			if (a == 0 && o[4] != -1)
				return (l);
		}
	if (!(a == 0 && o[4] != -1))
	{
		ft_putstr(num);
		ft_strdel(&num);
		return (l);
	}
	return (0);
}

void	ft_x(char *str, unsigned long long a, int j, int *s)
{
	int		*o;
	int		l;
	char	*num;

	o = ft_loop(j, str, 0);
	ft_cast_u(&a, str, 0, str[j]);
	if (a == 0)
		o[6] = 0;
	if (o[4] != -1)
		o[1] = 0;
	num = ft_hex(a, &l, str[j]);
	l = ft_strlen(num);
	if (o[6] == 1 && (o[4] += 2))
		l += 2;
	if (a == 0 && o[4] != -1)
		l = 0;
	if (o[0] == 1)
		l = ft_print_x(o, num, a, str[j]);
	*s += ft_space_x(o, l, str[j], a);
	if (o[0] != 1)
		l = ft_print_x(o, num, a, str[j]);
	*s += l;
	ft_memdel((void*)(&o));
}
