/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <oltkache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:33:32 by oltkache          #+#    #+#             */
/*   Updated: 2018/02/14 16:42:09 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_u2(unsigned int n)
{
	int		tmp;
	char	t[3];

	tmp = n;
	t[2] = '\0';
	t[0] = ((tmp >> 6) & 31) + 192;
	tmp = n;
	t[1] = (tmp & 63) + 128;
	write(1, t, 2);
}

void	ft_u3(unsigned int n)
{
	int		tmp;
	char	t[4];

	tmp = n;
	t[3] = '\0';
	t[0] = ((tmp >> 12) & 15) + 224;
	tmp = n;
	t[1] = ((tmp >> 6) & 63) + 128;
	tmp = n;
	t[2] = (tmp & 63) + 128;
	write(1, t, 3);
}

void	ft_u4(unsigned int n)
{
	int		tmp;
	char	t[5];

	tmp = n;
	t[4] = '\0';
	t[0] = ((tmp >> 18) & 7) + 240;
	tmp = n;
	t[1] = ((tmp >> 12) & 63) + 128;
	tmp = n;
	t[2] = ((tmp >> 6) & 63) + 128;
	tmp = n;
	t[3] = (tmp & 63) + 128;
	write(1, t, 4);
}

void	ft_putchar_u(unsigned int n, int *s)
{
	if (n <= 0x7F)
	{
		write(1, (char*)(&n), 1);
		*s += 1;
	}
	else if (n >= 0x80 && n <= 0x7FF)
	{
		ft_u2(n);
		*s += 2;
	}
	else if (n >= 0x800 && n <= 0xFFFF)
	{
		ft_u3(n);
		*s += 3;
	}
	else if (n >= 0x10000 && n <= 0x10FFFF)
	{
		ft_u4(n);
		*s += 4;
	}
}

void	ft_putstr_u(wchar_t *str, int *l)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 127 && (*l += 1))
			ft_putchar(str[i]);
		else
			ft_putchar_u(str[i], l);
		++i;
	}
}
