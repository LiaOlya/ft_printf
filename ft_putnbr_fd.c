/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <oltkache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:25:12 by oltkache          #+#    #+#             */
/*   Updated: 2018/02/14 17:03:56 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned long long	i;

	i = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
		{
			ft_putchar_fd('2', fd);
			n = -147483648;
		}
		n *= -1;
	}
	while (i * 10 <= (unsigned long long)n)
		i *= 10;
	ft_putchar_fd(n / i + '0', fd);
	while (i > 1)
	{
		i /= 10;
		if (n % (i * 10) != 0)
			ft_putchar_fd((n %= (i * 10)) / i + '0', fd);
		else
			ft_putchar_fd(n % i + '0', fd);
	}
}
