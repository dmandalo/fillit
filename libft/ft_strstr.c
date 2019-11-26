/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poretha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:23:57 by poretha           #+#    #+#             */
/*   Updated: 2019/09/13 08:47:28 by poretha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	if (!*needle)
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		if (*haystack == *needle &&
				ft_strnequ(haystack, needle, ft_strlen(needle)))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
