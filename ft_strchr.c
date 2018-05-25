/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <oltkache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:03:05 by oltkache          #+#    #+#             */
/*   Updated: 2018/02/14 17:04:57 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	while ((size_t)i <= len)
	{
		if (*s == (char)c)
			return ((char*)(s));
		++s;
		++i;
	}
	return (NULL);
}
