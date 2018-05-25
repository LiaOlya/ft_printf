/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <oltkache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:32:50 by oltkache          #+#    #+#             */
/*   Updated: 2018/02/16 12:24:20 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_conv(int i, va_list ap, char *s, int *k)
{
	int j;
	int y;

	j = ft_conversions(&s[++i]);
	if (s[i + j] == '%')
		ft_pc(&s[i], j, k);
	else if (s[i + j] == 's' || s[i + j] == 'S')
		ft_s(&s[i], va_arg(ap, wchar_t *), j, k);
	else if (s[i + j] == 'd' || s[i + j] == 'i' || s[i + j] == 'D')
		ft_d(&s[i], va_arg(ap, long long), j, k);
	else if (s[i + j] == 'c' || s[i + j] == 'C')
		ft_c(&s[i], va_arg(ap, unsigned int), j, k);
	else if (s[i + j] == 'x' || s[i + j] == 'X')
		ft_x(&s[i], va_arg(ap, unsigned long long), j, k);
	else if (s[i + j] == 'o' || s[i + j] == 'O')
		ft_o(&s[i], va_arg(ap, unsigned long long), j, k);
	else if (s[i + j] == 'u' || s[i + j] == 'U')
		ft_u(&s[i], va_arg(ap, unsigned long long), j, k);
	else if (s[i + j] == 'p')
		ft_p(&s[i], va_arg(ap, unsigned long long), j, k);
	else if ((y = ft_undef(s[i + j], k)) != 0)
		ft_un(y, &s[i], k);
	else
		return (-1);
	return (j);
}

int		ft_printf(char *s, ...)
{
	va_list	ap;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = 0;
	va_start(ap, s);
	while (s[i])
	{
		while (s[i] == '%')
		{
			j = ft_conv(i, ap, s, &k);
			if (j == -1)
				return (k);
			i += j + 2;
		}
		if (s[i] != '\0' && s[i] != '%' && (k += 1))
			ft_putchar(s[i++]);
	}
	va_end(ap);
	return (k);
}
