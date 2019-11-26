/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poretha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:22:56 by poretha           #+#    #+#             */
/*   Updated: 2019/09/10 23:20:18 by poretha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	i;
	char	*ptr;

	ptr = dst;
	i = 0;
	while (*ptr)
		ptr++;
	while (*src && i < n)
	{
		*(ptr++) = *(src++);
		i++;
	}
	*ptr = '\0';
	return (dst);
}
