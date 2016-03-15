/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <sid@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:48:37 by sid               #+#    #+#             */
/*   Updated: 2016/03/15 23:22:15 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

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
		tmp.vec.c.x = 0;
		while (*buf != '\0')
		{
			tmp.vec.c.z = ft_ator(buf);
			ft_dyna_append(&cur.vertices, &tmp, 1);
			NEXT_WORD;
			tmp.vec.c.x++;
		}
		tmp.vec.c.y++;
	}
	tmp.vec.c.z = 0;
	if (!(cur.dim = ft_memdup(&tmp, sizeof(tmp))))
		return (1);
	obj_add_center((t_gnode *)w, &cur);
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
			if (cur.vertices.chunck_count == 0)
				obj_del(&cur);
			else
				gnode_add_child((t_gnode *)w, (t_gnode *)&cur);
			cur = obj_new(buf + 2);
		}
		else if (*buf == 'v')
		{
			t_vrtx		tmp = (t_vrtx){{{0, 0, 0}}, {{0, 0, 0}}};
			for (int i = 0 ; i < 3 ; i++) {
				NEXT_WORD;
				tmp.vec.m[i] = ft_ator(buf);
			}
			ft_dyna_append(&cur.vertices, &tmp, 1);
		}
		else if (*buf == 'f')
		{
			t_face		temp = (t_face){{0, 0, 0, 0}};
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
	char			*ext;
	int				i;
	unsigned int	t;
	int				fd;
	const void		*tab[] = {"fdf", &parse_fdf, "obj", &parse_obj};

	i = -1;
	while (++i < length)
	{
		ext = param[i];
		while (*ext != '.' && *ext != '\0')
			ext++;
		if (*ext++ == '\0')
			continue ;
		t = 0;
		while (t < 4 && ft_strcmp(ext, tab[t]))
			t += 2;
		if (t == 4)
			continue ;
		else if ((fd = open(param[i], O_RDONLY)) == -1 || ((int (*)(t_obj *, int))(tab[t + 1]))(w, fd))
			return (1);
	}
	return (0);
}
