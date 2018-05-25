/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <oltkache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 12:06:25 by oltkache          #+#    #+#             */
/*   Updated: 2018/02/16 19:00:15 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_ch_f(char s)
{
	if (s == 'h' || s == 'l' || s == 'j' || s == 'z')
		return (1);
	return (0);
}

int		ft_hh(int *i, char *s)
{
	int j;
	int p;

	j = *i;
	p = 0;
	while (s[j] && s[j] == 'h')
	{
		++p;
		++j;
	}
	if (p % 2 != 0)
		return (0);
	*i = j - 1;
	return (1);
}

int		ft_ll(int *i, char *s)
{
	int j;
	int p;

	j = *i;
	p = 0;
	while (s[j] && s[j] == 'l')
	{
		++p;
		++j;
	}
	if (p % 2 == 0)
		return (0);
	*i = j - 1;
	return (1);
}

int		ft_h(int (*a)[5], char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0' && !ft_ch_f(s[i]))
		++i;
	while (s[i] != '\0' && ft_ch_f(s[i]))
	{
		if (s[i] == 'h' && ft_hh(&i, s) == 1)
			(*a)[2] = i;
		else if (s[i] == 'h')
			(*a)[0] = i;
		else if (s[i] == 'l')
			(*a)[1] = i;
		else if (s[i] == 'l' && ft_ll(&i, s) == 1)
			(*a)[4] = i;
		else if (s[i] == 'z')
			break ;
		else if (s[i] == 'j')
			(*a)[3] = i;
		++i;
	}
	return (i);
}

int		ft_flags(char *s, char *r, int *p)
{
	int i;
	int a[5];

	a[0] = -1;
	a[1] = -1;
	a[2] = -1;
	a[3] = -1;
	a[4] = -1;
	i = ft_h(&a, s);
	if (s[i] == 'z')
		*r = s[i];
	else if (a[3] != -1)
		*r = s[a[3]];
	else if (a[4] != -1 && (*p = 2))
		*r = s[a[4]];
	else if (a[1] != -1 && (*p = 1))
		*r = s[a[1]];
	else if (a[0] != -1 && (*p = 1))
		*r = s[a[0]];
	else if (a[2] != -1 && (*p = 2))
		*r = s[a[2]];
	else
		return (0);
	return (1);
}
