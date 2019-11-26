/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poretha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:25:09 by poretha           #+#    #+#             */
/*   Updated: 2019/09/17 07:33:06 by poretha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *nptr)
{
	int			nf;
	long		ret;

	nf = 1;
	ret = 0;
	while (*nptr && (*nptr == ' ' || *nptr == '\n' || *nptr == '\t' ||
				*nptr == '\v' || *nptr == '\r' || *nptr == '\f'))
		nptr++;
	if (*nptr == '-')
		nf = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr && ft_isdigit(*nptr))
	{
		if (ret <= (ret * 10 + (*nptr - '0')))
		{
			ret = ret * 10 + (*nptr - '0');
			nptr++;
		}
		else if (nf == 1)
			return (-1);
		else
			return (0);
	}
	return ((int)ret * nf);
}
