/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <oltkache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:16:26 by oltkache          #+#    #+#             */
/*   Updated: 2018/02/15 16:25:11 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_conversions(char *a)
{
	int i;
	int j;

	i = 0;
	while (a[i])
	{
		j = 0;
		while (CONV[j] && UNDEF[j])
		{
			if (CONV[j] == a[i] || UNDEF[j] == a[i])
				return (i);
			++j;
		}
		++i;
	}
	return (0);
}

int		ft_num_len(long long num, unsigned int sys)
{
	unsigned int res;

	res = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		++res;
	while ((unsigned long long)num >= 1)
	{
		num /= sys;
		++res;
	}
	return ((int)res);
}

int		ft_num_len_u(unsigned long long num, unsigned int sys)
{
	unsigned int res;

	res = 0;
	if (num == 0)
		return (1);
	while (num >= 1)
	{
		num /= sys;
		++res;
	}
	return ((int)res);
}

void	ft_putnbr_long(long long n)
{
	char			*num;
	unsigned int	i;
	int				num_len;
	int				temp;

	num_len = ft_num_len(n, 10);
	i = num_len - 1;
	num = (char*)malloc(sizeof(char) * (num_len + 1));
	num[num_len] = '\0';
	if (n == 0)
		num[0] = '0';
	if (n < 0)
		num[0] = '-';
	while ((unsigned long long)n >= 1)
	{
		temp = n % 10;
		if (temp < 0)
			temp *= -1;
		num[i] = temp + '0';
		--i;
		n /= 10;
	}
	ft_putstr(num);
	ft_strdel(&num);
}

void	ft_putnbr_long_u(unsigned long long n)
{
	char			*num;
	unsigned int	i;
	int				num_len;
	int				temp;

	num_len = ft_num_len_u(n, 10);
	i = num_len - 1;
	num = (char*)malloc(sizeof(char) * (num_len + 1));
	num[num_len] = '\0';
	if (n == 0)
		num[0] = '0';
	while ((unsigned long long)n >= 1)
	{
		temp = n % 10;
		num[i] = temp + '0';
		--i;
		n /= 10;
	}
	ft_putstr(num);
	ft_strdel(&num);
}
