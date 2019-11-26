/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poretha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:23:44 by poretha           #+#    #+#             */
/*   Updated: 2019/09/11 08:55:55 by poretha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	len;

	len = ft_strlen(s);
	i = 1;
	if (c == '\0')
		return ((char *)(s + len));
	while (i <= len && s[len - i] != (char)c)
		i++;
	if (s[len - i] == (char)c)
		return ((char *)(s + len - i));
	return (NULL);
}
