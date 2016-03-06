/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <sid@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:48:37 by sid               #+#    #+#             */
/*   Updated: 2016/03/06 14:14:00 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define NEXT_WORD while(*buf++ != ' ')

int		parse_fdf(t_obj *w, int fd)
{
	t_obj		cur;
	char		*buf;
	t_vrtx		tmp;

	cur = obj_new("FDF");
	tmp = (t_vrtx){{{0,0,0}},{{0,0,0}}};
	while (get_next_line(fd, &buf) == 1)
	{
		while (*buf != '\0')
		{
			tmp.vec.z = ft_ator(buf);
			ft_dyna_append(&cur.vertices, &tmp);
			NEXT_WORD;
			tmp.vec.x++;
		}
		tmp.vec.y++;
	}
	if (!(cur->dim = ft_memdup(&tmp, sizeof(tmp))))
		return (1);
	obj_add_center(w, &cur);
	return (0);
}

int		parse_obj(t_obj *w, int fd)
{
	t_obj		cur;
	char		*buf;

	cur = obj_new("Others");
	while (get_next_line(fd, &buf) == 1)
	{
		if (*buf == 'o')
		{
			if (cur.)
			cur = obj_new(buf + 2);
			gnode_add_child(w, &cur);
		}
		else if (*buf == 'v')
		{
			t_vrtx		tmp = (t_vrtx){{{0,0,0}},{{0,0,0}}};
			for (int i = 0 ; i < 3 ; i++) {
				NEXT_WORD;
				tmp.vec.m[i] = ft_ator(buf);
			}
			ft_dyna_append(&cur.vertices, &tmp, 1);
		}
		else if (*buf == 'f')
		{
			t_face		temp = (t_face){{0,0,0,0}};
			for (int i = 0 ; i < 4 ; i++) {
				NEXT_WORD;
				temp.index[i] = ft_atoi(buf);
			}
			ft_dyna_append(&cur.faces, &temp, 1);
		}
	}
	return (0);
}

int		read_av(t_obj *w, int length, char **param)
{
	char			*c;
	int				i;
	unsigned int	t;
	int				fd;
	const void		*tab[] = {"fdf", &parse_fdf, "obj", &parse_obj};

	i = -1;
	while (++i < length)
	{
		c = param[i];
		while (*c != '.' && *c != '\0')
			c++;
		if (*c == '\0')
			continue ;
		t = 0;
		while (t < sizeof(tab) && ft_strcmp(c, tab[t]))
			t += 2;
		if (t == sizeof(tab))
			continue ;
		else if ((fd = open(param[i])) != -1)
			if (((void (*)(t_obj *, int))(tab[t - 1]))(w, fd))
				return (1);
		else
			return (2);
	}
	return (0);
}
