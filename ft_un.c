/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <oltkache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:55:50 by oltkache          #+#    #+#             */
/*   Updated: 2018/02/16 12:31:09 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	ft_undef(char str, int *k)
{
	int i;

	i = 0;
	while (UNDEF[i] != '\0')
	{
		if (UNDEF[i] == str && (*k += 1))
			return (str);
		++i;
	}
	return (0);
}

void	ft_loop_un(int **l, char *str, char y)
{
	int i;

	i = 0;
	while (str[i] != y)
	{
		if (str[i] == '-')
		{
			(*l)[0] = 1;
			++i;
		}
		else if (str[i] == '0')
		{
			(*l)[1] = 1;
			++i;
		}
		else if (ft_isdigit(str[i]))
		{
			(*l)[2] = ft_atoi(&str[i]);
			i += ft_num_len((*l)[2], 10);
		}
		else
			++i;
	}
}

void	ft_un(char y, char *str, int *j)
{
	int *l;

	l = ft_intnew(3);
	ft_loop_un(&l, str, y);
	if (l[0] == 1)
		ft_putchar(y);
	if (l[1] == 1)
		ft_spaces(l[2] - 1, 2);
	else
		ft_spaces(l[2] - 1, 1);
	if (l[0] != 1)
		ft_putchar(y);
	if (l[2] > 1)
		*j += l[2] - 1;
}
