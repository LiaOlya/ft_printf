/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <oltkache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:14:33 by oltkache          #+#    #+#             */
/*   Updated: 2018/02/15 12:25:42 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	size_t	len;
	size_t	i;
	size_t	n;
	char	*res;

	len = ft_strlen(s);
	i = 0;
	n = len - 1;
	res = ft_strnew(len);
	while (i < len)
	{
		res[i] = s[n];
		++i;
		--n;
	}
	return (res);
}
