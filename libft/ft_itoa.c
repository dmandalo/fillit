/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poretha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 10:15:31 by poretha           #+#    #+#             */
/*   Updated: 2019/09/16 08:35:14 by poretha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	getnorm_n(int n)
{
	unsigned int	un;

	if (n == -2147483648)
		un = 2147483648;
	else if (n < 0)
		un = -1 * n;
	else
		un = n;
	return (un);
}

static char			*setstr_n(unsigned int n, int f)
{
	char			*ptr;
	int				i;
	int				j;
	unsigned int	un;

	i = 1;
	j = 1;
	un = n;
	while ((n /= 10) != 0)
		i++;
	if ((ptr = ft_strnew(i + f)) == NULL)
		return (NULL);
	while (i-- > 1)
		j *= 10;
	if (f)
		i = 1;
	else
		i = 0;
	while (j >= 1)
	{
		ptr[i++] = un / j % 10 + '0';
		j /= 10;
	}
	return (ptr);
}

char				*ft_itoa(int n)
{
	unsigned int	un;
	int				f;
	char			*ptr;

	f = 0;
	if (n < 0)
		f = 1;
	un = getnorm_n(n);
	if ((ptr = setstr_n(un, f)) == NULL)
		return (NULL);
	if (f)
		ptr[0] = '-';
	return (ptr);
}
