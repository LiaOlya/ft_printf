/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <oltkache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:02:35 by oltkache          #+#    #+#             */
/*   Updated: 2018/02/14 17:05:15 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int j;
	int len1;
	int len2;

	len1 = ft_strlen(s1);
	if (n >= ft_strlen(s2))
		len2 = ft_strlen(s2);
	else
		len2 = n;
	j = len2 + len1;
	s1[j] = '\0';
	while (j > len1)
	{
		s1[j - 1] = s2[j - len1 - 1];
		--j;
	}
	return (s1);
}
