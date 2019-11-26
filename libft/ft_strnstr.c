/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poretha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:24:11 by poretha           #+#    #+#             */
/*   Updated: 2019/09/16 22:42:00 by poretha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	ln;
	size_t	i;

	i = 0;
	ln = ft_strnlen(little, len);
	if (ft_strlen(big) < ft_strlen(little) || ft_strlen(little) > len)
		return (NULL);
	if (ln > ft_strlen(big))
		return (NULL);
	if (!little || !*little || (0 == ln))
		return ((char *)big);
	while (*big != '\0' && i < len)
	{
		if (*big == *little && len - i >= ln && ft_strnequ(big, little, ln))
			return ((char *)big);
		big++;
		i++;
	}
	return (NULL);
}
