/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:18:03 by poretha           #+#    #+#             */
/*   Updated: 2019/11/14 20:11:00 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetrino	**create_tetrino(int len)
{
	t_tetrino		**tets;
	t_tetrino		*tet;
	int				i;

	i = 0;
	tets = (t_tetrino **)malloc(sizeof(t_tetrino *) * (len + 1));
	if (!tets)
		return (ft_tetreaderror());
	tets[len] = NULL;
	while (i < len)
	{
		tet = (t_tetrino *)malloc(sizeof(t_tetrino));
		if (!tet)
		{
			while (i > 0)
				free(tets[--i]);
			free(tets);
			return (ft_tetreaderror());
		}
		tets[i++] = tet;
	}
	tets[i] = 0;
	return (tets);
}

static t_tetrino	**tetconvert(char *tetriminos, t_tetrino **dst, int len)
{
	t_point			p;

	p.y = 0;
	p.x = 0;
	while (p.x < len)
	{
		dst[p.x]->c = 'A' + p.x;
		dst[p.x]->type = ft_gettet(&tetriminos[p.y]);
		dst[p.x]->height = ft_tetheight(dst[p.x]->type);
		dst[p.x]->width = ft_tetwidth(dst[p.x]->type);
		ft_setshapes(dst[p.x]);
		if (!dst[p.x]->type)
		{
			while (len > 0)
				free(dst[--len]);
			free(dst);
			return (ft_tetfree(tetriminos));
		}
		else
			p.y += 20;
		p.x++;
		p.y++;
	}
	free(tetriminos);
	return (dst);
}

static t_tetrino	**checkchars(char *tet)
{
	int				i;
	int				len;
	t_tetrino		**temp;

	i = 0;
	if (!tet)
	{
		ft_putendl("error");
		return (NULL);
	}
	while (tet[i])
	{
		if (tet[i] != '#' && tet[i] != '.' && tet[i] != '\n')
			return (ft_tetfree(tet));
		i++;
	}
	len = ft_strlen(tet);
	if ((len + 1) % 21 != 0 ||
		(temp = create_tetrino((len + 1) / 21)) == NULL)
		return (ft_tetfree(tet));
	return (tetconvert(tet, temp, (len + 1) / 21));
}

t_tetrino			**ft_tetread(int fd)
{
	char			*tmp;
	int				cnt;
	char			*tetriminos;
	char			buff[BUFF_SIZE + 1];

	tetriminos = NULL;
	if (fd < 0)
		return (ft_tetreaderror());
	while ((cnt = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[cnt] = '\0';
		if (!tetriminos)
			tetriminos = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(tetriminos, buff);
			free(tetriminos);
			tetriminos = tmp;
		}
		if (!tetriminos)
			return (ft_tetreaderror());
	}
	return (checkchars(tetriminos));
}
