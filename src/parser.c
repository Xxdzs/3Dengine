/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <sid@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:48:37 by sid               #+#    #+#             */
/*   Updated: 2016/03/04 19:39:55 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse_fdf(t_obj *w, int fd)
{
	t_obj		*cur;
	char		*buf;
	char		*c;

}

void	parse_obj(t_obj *w, int fd)
{
	t_obj		*cur;
	char		*buf;

	cur = w;
	while (get_next_line(fd, &buf) == 1)
	{
		if (*buf == 'o')
		{
			cur = obj_alloc(buf + 2);
			gnode_add_child(w, cur);
		}
		else if (*buf == '')
		{

		}
	}
}

int		read_av(t_obj *w, int length, char **param)
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
			((void (*)(t_obj *, int))(tab[t - 1]))(w, fd);
		else
			return (2);
	}
	return (0);
}
