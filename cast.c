/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <oltkache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:43:42 by oltkache          #+#    #+#             */
/*   Updated: 2018/02/16 10:24:01 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_cast1(long long *a, char s, int p)
{
	if (s == 'h')
	{
		if (p == 2)
			*a = (char)(*a);
		if (p == 1)
			*a = (short)(*a);
	}
	else if (s == 'l')
	{
		if (p == 2)
			*a = (long long)(*a);
		if (p == 1)
			*a = (long)(*a);
	}
	else if (s == 'z')
		*a = (size_t)(*a);
	else if (s == 'j')
		*a = (intmax_t)(*a);
}

int		ft_cast(long long *a, char *str, int c)
{
	int		p;
	int		d;
	char	s;

	d = 0;
	p = 0;
	if ((ft_flags(str, &s, &p)) != 0 && c != 1)
		ft_cast1(a, s, p);
	else if (c != 1)
		*a = (int)(*a);
	if (c != 1 && *a < 0 && (*a *= -1))
		d = 1;
	return (d);
}

int		ft_cast_u1(unsigned long long *a, char *str, int c, int i)
{
	if (str[i] == 'h' && c != 1)
	{
		if (str[i + 1] && str[i + 1] == 'h')
			*a = (unsigned char)(*a);
		else
			*a = (unsigned short)(*a);
	}
	else if (str[i] == 'l')
	{
		if (str[i + 1] && str[i + 1] == 'l')
			*a = (unsigned long long)(*a);
		else
			*a = (unsigned long)(*a);
	}
	else if (str[i] == 'z')
		*a = (size_t)(*a);
	else if (str[i] == 'j')
		*a = (uintmax_t)(*a);
	else
		return (0);
	return (1);
}

void	ft_cast_u(unsigned long long *a, char *str, int c, char s)
{
	int i;
	int k;

	i = 0;
	while (str[i] && str[i] != s)
	{
		if (str[i] == 'h' || str[i] == 'l' || str[i] == 'z' || str[i] == 'j')
			break ;
		++i;
	}
	k = ft_cast_u1(a, str, c, i);
	if (k == 0)
	{
		if (c == 1)
			*a = (unsigned long)(*a);
		else
			*a = (unsigned int)(*a);
	}
}
