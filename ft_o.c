/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <oltkache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:23:43 by oltkache          #+#    #+#             */
/*   Updated: 2018/02/16 17:37:22 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_octal(unsigned long long a, int *l)
{
	int		b;
	char	*str;
	int		i;
	char	*new;

	i = 0;
	str = ft_strnew(ft_num_len_u(a, 8));
	if (a == 0)
		str[i] = 0 + '0';
	while (a >= 1)
	{
		b = a % 8;
		if (b < 8 && a > 7)
			if (b < 8)
				str[i++] = b + '0';
		if (a < 8)
			str[i++] = a + '0';
		a /= 8;
	}
	if (l != NULL)
		*l += ft_strlen(str);
	new = ft_strrev(str);
	ft_strdel(&str);
	return (new);
}

void	ft_print_o(int *o, int *s, unsigned long long a, char *num)
{
	int l;

	l = ft_strlen(num);
	if (a == 0 && o[4] != -1)
		l = 0;
	if (o[6] == 1)
		l += 1;
	if (o[6] == 1 && (o[1] != 1 || a == 0))
		write(1, "0", 1);
	if (o[4] != -1)
		if (o[4] > l)
		{
			ft_spaces(o[4] - l, 2);
			*s += (o[4] - l);
		}
	if (!(a == 0 && o[4] != -1) && !(a == 0 && o[6] != 0))
	{
		ft_putstr(num);
		*s += ft_strlen(num);
	}
	if (!(a == 0 && o[6] != 0))
		ft_strdel(&num);
}

void	ft_space_o(int *o, int *s, int l)
{
	if (o[3] - l > 0 && o[3] > o[4])
	{
		if (o[1] == 1 && o[0] != 1)
		{
			if (o[6] == 1)
				write(1, "0", 1);
			ft_spaces(o[3] - l, 2);
			*s += (o[3] - l);
		}
		else
		{
			if (o[4] > l && (*s += (o[3] - o[4])))
				ft_spaces(o[3] - o[4], 1);
			else
			{
				ft_spaces(o[3] - l, 1);
				*s += (o[3] - l);
			}
		}
	}
}

void	ft_o(char *str, unsigned long long a, int j, int *s)
{
	int		*o;
	int		c;
	int		l;
	char	*num;

	l = 0;
	c = 0;
	if (str[j] == 'O')
		c = 1;
	o = ft_loop(j, str, 0);
	ft_cast_u(&a, str, c, str[j]);
	num = ft_octal(a, &l);
	if (o[6] != 1 && a == 0 && o[4] != -1)
		l = 0;
	if (o[6] == 1)
	{
		*s += 1;
		l += 1;
	}
	if (o[0] == 1)
		ft_print_o(o, s, a, num);
	ft_space_o(o, s, l);
	if (o[0] != 1)
		ft_print_o(o, s, a, num);
	ft_memdel((void*)(&o));
}
