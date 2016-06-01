/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <sid@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:48:37 by sid               #+#    #+#             */
/*   Updated: 2016/06/01 18:57:56 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

#include <stdio.h> // <==

static inline void	next_word(char **buf)
{
	while (**buf != ' ' && **buf != '\0')
		(*buf)++;
	while (**buf != '\0' && **buf == ' ')
		(*buf)++;
}

int		parse_fdf(t_obj *w, int fd)
{
	t_obj		cur;
	char		*buf;
	t_vrtx		tmp;

	printf("--> fdf-parsin\n"); // <--
	cur = obj_new("FDF");
	tmp = NEW_VRTX;
	if (!(cur.dim = vec3_alloc(0, 0, 0)))
		return (1);
	while (get_next_line(fd, &buf) == 1)
	{
		X(tmp.vec) = 0;
		while (*buf != '\0')
		{
			Z(tmp.vec) = ft_ator(buf);
			ft_dyna_append(&cur.vertices, &tmp, 1);
			next_word(&buf);
			X(tmp.vec)++;
			if (XP(cur.dim) < X(tmp.vec))
				XP(cur.dim) = X(tmp.vec);
		}
		Y(tmp.vec)++;
	}
	YP(cur.dim) = Y(tmp.vec);
//	obj_add_center((t_gnode *)w, &cur);
	gnode_add_child((t_gnode *)w, (t_gnode *)&cur);
	return (0);
}

int		parse_obj(t_obj *w, int fd)
{
	t_obj		cur;
	char		*buf;

	printf("--> obj-parsin\n"); // <--
	cur = obj_new("Others");
	while (get_next_line(fd, &buf) == 1)
	{
		if (*buf == 'o')
		{
			if (cur.vertices.chunck_count == 0)
				obj_del(&cur);
			else
				gnode_add_child((t_gnode *)w, (t_gnode *)&cur);
			cur = obj_new(buf + 2);
		}
		else if (*buf == 'v')
		{
			t_vrtx		tmp = NEW_VRTX;
			for (int i = 0 ; i < 3 ; i++) {
				next_word(&buf);
				tmp.vec.v.m[i] = ft_ator(buf);
			}
			ft_dyna_append(&cur.vertices, &tmp, 1);
		}
		else if (*buf == 'f')
		{
			t_face		temp = (t_face){{0, 0, 0, 0}};
			for (int i = 0 ; i < 4 ; i++) {
				next_word(&buf);
				temp.index[i] = ft_atoi(buf);
			}
			ft_dyna_append(&cur.faces, &temp, 1);
		}
	}
	return (0);
}

int		read_av(t_obj *w, int length, char **param)
{
	char			*ext;
	int				i;
	unsigned int	t;
	int				fd;
	const void		*tab[] = {"fdf", &parse_fdf, "obj", &parse_obj};

	i = -1;
	while (++i < length)
	{
		ext = ft_strrchr(param[i], '.');
		if (ext++ == NULL)
			continue;
		t = 0;
		while (t < 4 && ft_strcmp(ext, tab[t]))
			t += 2;
		if (t == 4)
			continue;
		else if ((fd = open(param[i], O_RDONLY)) == -1
			|| ((int (*)(t_obj *, int))(tab[t + 1]))(w, fd))
			return (1);
	}
	return (0);
}
