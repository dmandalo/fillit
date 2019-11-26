/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poretha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:22:40 by poretha           #+#    #+#             */
/*   Updated: 2019/09/10 19:43:44 by poretha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *dst, const char *src)
{
	char	*ptr;

	ptr = dst;
	while (*ptr)
		ptr++;
	while (*src)
		*(ptr++) = *(src++);
	*ptr = '\0';
	return (dst);
}
