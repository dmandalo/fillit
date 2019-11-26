/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poretha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:23:10 by poretha           #+#    #+#             */
/*   Updated: 2019/09/18 08:13:13 by poretha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	ln;

	i = 0;
	j = 0;
	ln = 0;
	i = ft_strlen(dst);
	if (i >= size)
	{
		ln = size + ft_strlen(src);
		return (ln);
	}
	ln = i + ft_strlen(src);
	while (*src && j < size - i - 1)
	{
		dst[j + i] = *(src++);
		j++;
	}
	dst[i + j] = '\0';
	return (ln);
}
