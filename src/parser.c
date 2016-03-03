/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <sid@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:48:37 by sid               #+#    #+#             */
/*   Updated: 2016/03/03 17:26:26 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse_fdf(t_env *w, int fd)
{
	t_gnode *cur;

	cur = &(w->world);
}

void	parse_obj(t_env *w, int fd)
{
	t_gnode *cur;
	char	*buf;

	cur = &(w->world);
	while (get_next_line(fd, &buf) == 1)
	{
		if (*buf == 'o')
		{
			cur = obj_alloc();
			gnode_add_child(&w->world, t_g)
		}
	}
}

int		read_av(t_env *w, int length, char **param)
{
	char			*c;
	int				i;
	unsigned int	t;
	int				fd;
	const void		*tab[] = {"fdf", &parse_fdf, "obj", &parse_obj};

	i = length;
	while (i-- > 0)
	{
		c = param[i];
		while (*c++ != '.')
			;
		t = 0;
		while (t < sizeof(tab) && ft_strcmp(c, tab[t]))
			t += 2;
		if (t == sizeof(tab))
			return (1);
		else if ((fd = open(param[i])) != -1)
			((void (*)(t_env *, int))(tab[t - 1]))(w, fd);
		else
			return (2);
	}
	return (0);
}
