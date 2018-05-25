/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <oltkache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:24:10 by oltkache          #+#    #+#             */
/*   Updated: 2018/02/16 16:02:58 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_c(unsigned int a, int u, int *k)
{
	if (u == 1)
		ft_putchar_u(a, k);
	else
	{
		ft_putchar(a);
		*k += 1;
	}
}

void	ft_c(char *str, unsigned int a, int j, int *k)
{
	int *l;

	l = ft_loop(j, str, 1);
	if (str[j] == 'C' && MB_CUR_MAX > 1)
		l[7] = 1;
	l[3] -= 1;
	if (l[0] == 1)
		ft_print_c(a, l[7], k);
	if (l[3] > 0 && (*k += l[3]))
	{
		if (l[1] == 1 && l[0] != 1)
			ft_spaces(l[3], 2);
		else
			ft_spaces(l[3], 1);
	}
	if (l[0] != 1)
		ft_print_c(a, l[7], k);
	ft_memdel((void*)(&l));
}
