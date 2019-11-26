/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poretha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:21:02 by poretha           #+#    #+#             */
/*   Updated: 2019/09/10 19:47:05 by poretha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	ch;

	s = (unsigned char *)str;
	ch = (unsigned char)c;
	while (n-- > 0)
		if (*s == ch)
			return ((void *)s);
		else
			s++;
	return (0);
}
