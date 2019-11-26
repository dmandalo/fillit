/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poretha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 10:12:23 by poretha           #+#    #+#             */
/*   Updated: 2019/09/10 19:39:56 by poretha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	if (NULL == (ptr = (char *)malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (*s1)
		ptr[i++] = *(s1++);
	while (*s2)
		ptr[i++] = *(s2++);
	ptr[i] = '\0';
	return (ptr);
}
