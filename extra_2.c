/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <oltkache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:41:45 by oltkache          #+#    #+#             */
/*   Updated: 2018/02/16 14:54:57 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_spaces(int p, int n)
{
	char	*new;
	char	str;
	int		i;

	if (p < 0)
		return ;
	if (n == 1)
		str = ' ';
	if (n == 2)
		str = '0';
	i = 0;
	new = (char*)malloc(sizeof(char) * (p + 1));
	new[p] = '\0';
	while (i < p)
	{
		new[i] = str;
		++i;
	}
	write(1, new, ft_strlen(new));
	ft_strdel(&new);
}

int		ft_increm_1(int *f, int *i)
{
	*i += 1;
	*f -= 1;
	return (1);
}

int		ft_increm_2(char *str, int *f, int *i, int ch)
{
	int y;

	if (ch == 1)
	{
		y = ft_atoi(str);
		*i += ft_num_len(y, 10);
		*f -= ft_num_len(y, 10);
		return (y);
	}
	if (ch == 2)
	{
		y = ft_atoi(str);
		if (ft_isdigit(str[0]))
		{
			*i += ft_num_len(y, 10);
			*f -= ft_num_len(y, 10);
		}
		ft_increm_1(f, i);
		return (y);
	}
	return (0);
}

char	*ft_hex(unsigned long long a, int *l, char c)
{
	int		b;
	char	*str;
	int		i;
	char	*new;

	i = 0;
	str = ft_strnew(ft_num_len_u(a, 16));
	if (a == 0)
		str[i] = 0 + '0';
	while (a >= 1)
	{
		if ((b = a % 16) < 16 && a > 15)
			str[i++] = ft_hex_ch(b, a, c, 0);
		if (a < 10)
			str[i++] = a + '0';
		else if (a > 9 && a < 16)
			str[i++] = ft_hex_ch(b, a, c, 1);
		a /= 16;
	}
	*l += ft_strlen(str);
	new = ft_strrev(str);
	ft_strdel(&str);
	return (new);
}

int		ft_h_d(int a, int *l, int d, int *k)
{
	if (a == 0 && l[4] == 0)
	{
		if (l[2] == 1 && (*k += 1))
			ft_sign(d);
		ft_spaces(l[3], 1);
		*k += l[3];
		return (1);
	}
	return (0);
}
