/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poretha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 10:14:34 by poretha           #+#    #+#             */
/*   Updated: 2019/09/18 08:29:27 by poretha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**get_arraywords(char const *s, char c)
{
	int		i;
	int		flag;
	char	**ptr;

	i = 0;
	flag = 1;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (flag && *s != c)
		{
			flag = 0;
			i++;
		}
		else if (*s == c)
			flag = 1;
		s++;
	}
	if ((ptr = (char **)malloc(sizeof(char *) * (i + 1))))
		return (ptr);
	else
		return (NULL);
}

static char	*get_word(char const *s, char c)
{
	int		i;
	char	*ptr;

	i = 0;
	while (*s && *s == c)
		s++;
	while (s[i] && s[i] != c)
		i++;
	if ((ptr = ft_strnew(i)) == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static void	ft_freearray(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ptr;
	char	*ptr_w;
	int		i;

	if (NULL == (ptr = get_arraywords(s, c)))
		return (NULL);
	i = 0;
	while (*s)
		if (*s && *s != c)
		{
			ptr_w = get_word(s, c);
			if (ptr_w == NULL)
			{
				ft_freearray(ptr, i);
				return (NULL);
			}
			ptr[i] = ptr_w;
			s += (ft_strlen(ptr_w));
			i++;
		}
		else
			s++;
	ptr[i] = NULL;
	return (ptr);
}
