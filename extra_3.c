/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <oltkache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:44:38 by oltkache          #+#    #+#             */
/*   Updated: 2018/02/16 16:46:16 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_strlen_u(wchar_t *l)
{
	int i;
	int ln;

	i = 0;
	ln = 0;
	while (l[i])
	{
		if (l[i] <= 0x7F)
			ln += 1;
		else if (l[i] >= 0x80 && l[i] <= 0x7FF)
			ln += 2;
		else if (l[i] >= 0x800 && l[i] <= 0xFFFF)
			ln += 3;
		else if (l[i] >= 0x10000 && l[i] <= 0x10FFFF)
			ln += 4;
		++i;
	}
	return (ln);
}

int			ft_h_sub(wchar_t *s, int i, int l, int *tmp)
{
	if (s[i] <= 0x7F)
	{
		if (*tmp + 1 > l)
			return (1);
		*tmp += 1;
	}
	else if (s[i] >= 0x80 && s[i] <= 0x7FF)
	{
		if (*tmp + 2 > l)
			return (1);
		*tmp += 2;
	}
	else if (s[i] >= 0x800 && s[i] <= 0xFFFF)
	{
		if (*tmp + 3 > l)
			return (1);
		*tmp += 3;
	}
	else if (s[i] >= 0x10000 && s[i] <= 0x10FFFF)
	{
		if (*tmp + 4 < l)
			return (1);
		*tmp += 4;
	}
	return (0);
}

wchar_t		*ft_sub_u(wchar_t *s, int l)
{
	int			i;
	int			j;
	int			tmp;
	wchar_t		*res;

	i = 0;
	j = 0;
	tmp = 0;
	while (s[i])
	{
		if (ft_h_sub(s, i, l, &tmp) == 1)
			break ;
		++i;
	}
	res = (wchar_t*)malloc(sizeof(wchar_t) * (i + 1));
	res[i] = '\0';
	while (j < i)
	{
		res[j] = s[j];
		++j;
	}
	return (res);
}
