/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poretha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 09:55:47 by poretha           #+#    #+#             */
/*   Updated: 2019/09/07 09:58:01 by poretha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if ((ptr = malloc(size)) == NULL)
		return (NULL);
	while (i < size)
		ptr[i++] = 0;
	return ((void *)ptr);
}
