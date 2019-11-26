/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poretha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:19:34 by poretha           #+#    #+#             */
/*   Updated: 2019/09/05 10:19:38 by poretha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char	*temp;
	unsigned char	ch;

	temp = (unsigned char *)ptr;
	ch = (unsigned char)c;
	while (n-- > 0)
		*(temp++) = ch;
	return ((void *)ptr);
}
