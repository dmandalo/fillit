/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poretha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 10:14:34 by poretha           #+#    #+#             */
/*   Updated: 2019/09/16 18:56:31 by poretha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find(char const s, char const *c)
{
	while (*c)
	{
		if (s == *c)
			return (1);
		c++;
	}
	return (0);
}

int			ft_strcntwords(char const *s, char const *c)
{
	int		i;
	int		flag;

	i = 0;
	flag = 1;
	if (!s || !c)
		return (0);
	while (*s)
	{
		if (flag && ft_find(*s, c))
		{
			flag = 0;
			i++;
		}
		else if (ft_find(*s, c))
			flag = 1;
		s++;
	}
	return (i);
}
