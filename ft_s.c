/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <oltkache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:24:17 by oltkache          #+#    #+#             */
/*   Updated: 2018/02/16 16:43:55 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_space_s(int *l, wchar_t *a, char *t, int r)
{
	int j;

	j = 0;
	if (l[7] == 1)
		j = l[3] - ft_strlen_u(a);
	else
	{
		if (r == 1)
			j = l[3] - ft_strlen(t);
		else
			j = l[3] - ft_strlen((char*)a);
	}
	if (l[1] == 1 && l[0] != 1)
		ft_spaces(j, 2);
	else
		ft_spaces(j, 1);
	if (j > 0)
		return (j);
	return (0);
}

int		ft_print_s(wchar_t *a, char *t, int f, int r)
{
	int s;

	s = 0;
	if (f == 1)
		ft_putstr_u(a, &s);
	else
	{
		if (r == 1)
		{
			ft_putstr(t);
			s += ft_strlen(t);
		}
		else
		{
			ft_putstr((char*)a);
			s += ft_strlen((char*)a);
		}
	}
	return (s);
}

int		ft_ch_s(wchar_t *a, int *s, int *l)
{
	if (a == NULL)
	{
		write(1, "(null)", 6);
		*s += 6;
		ft_memdel((void*)(&l));
		return (1);
	}
	return (0);
}

void	ft_del(int r, int *l, char *t, wchar_t *a)
{
	if (r == 1 && l[7] != 1)
		ft_memdel((void*)(&t));
	else if (r == 1 && l[7] == 1)
		ft_memdel((void*)(&a));
	ft_memdel((void*)(&l));
}

void	ft_s(char *str, wchar_t *a, int j, int *s)
{
	int		*l;
	int		r;
	char	*t;

	r = 0;
	t = NULL;
	l = ft_loop(j, str, 0);
	if (str[j] == 'S')
		l[7] = 1;
	if (ft_ch_s(a, s, l) == 1)
		return ;
	if (l[7] != 1)
	{
		if (l[4] != -1 && l[4] < (int)ft_strlen((char*)a) && (r = 1))
			t = ft_strsub((char*)a, 0, l[4]);
	}
	else if (l[4] != -1 && l[4] < ft_strlen_u(a) && (r = 1))
		a = ft_sub_u(a, l[4]);
	if (l[0] == 1)
		*s += ft_print_s(a, t, l[7], r);
	*s += ft_space_s(l, a, t, r);
	if (l[0] != 1)
		*s += ft_print_s(a, t, l[7], r);
	ft_del(r, l, t, a);
}
