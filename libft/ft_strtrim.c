/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poretha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 10:13:34 by poretha           #+#    #+#             */
/*   Updated: 2019/09/16 19:03:07 by poretha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	sw;
	size_t	ew;
	int		i;
	char	*ptr;

	if (!s)
		return (NULL);
	sw = 0;
	if ((ew = ft_strlen(s)) == 0)
		return (ft_strnew(0));
	else
		ew--;
	i = 0;
	while (s[sw] && (s[sw] == ' ' || s[sw] == '\n' || s[sw] == '\t'))
		sw++;
	while (ew > 0 && (s[ew] == ' ' || s[ew] == '\n' || s[ew] == '\t'))
		ew--;
	ptr = ((ew == 0) ? (ft_strnew(0)) : (ft_strnew(ew - sw + 1)));
	if (!ptr)
		return (NULL);
	while (sw <= ew)
		ptr[i++] = s[sw++];
	return (ptr);
}
