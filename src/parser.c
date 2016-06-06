/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <sid@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:48:37 by sid               #+#    #+#             */
/*   Updated: 2016/06/07 00:41:32 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

static inline void	next_word(char **buf)
{
	while (**buf != ' ' && **buf != '\0')
		(*buf)++;
	while (**buf != '\0' && **buf == ' ')
		(*buf)++;
}
int					parse_fdf(t_obj *o, int fd)
{
	t_obj		cur;
	char		*buf;
	t_vrtx		tmp;

	cur = obj_new("FDF");
	tmp = NEW_VRTX;
	if (!(cur.dim = vec3_alloc(0, 0, 0)))
		return (1);
	while (get_next_line(fd, &buf) == 1)
	{
		X(tmp.vec) = 0;
		while (*buf != '\0')
		{
			Z(tmp.vec) = -ft_ator(buf);
			ft_dyna_append(&cur.vertices, &tmp, 1);
			next_word(&buf);
			X(tmp.vec)++;
			if (XP(cur.dim) < X(tmp.vec))
				XP(cur.dim) = X(tmp.vec);
		}
		Y(tmp.vec)++;
	}
	YP(cur.dim) = Y(tmp.vec);
	gnode_add_child((t_gnode *)o, obj_adjust(&cur));
	return (0);
}

static inline void	add_vrtx(char **buf, t_obj *cur)
{
	t_vrtx		tmp;
	size_t		i;

	tmp = NEW_VRTX;
	i = 0;
	while (i < 3)
	{
		next_word(buf);
		tmp.vec.v.m[i] = ft_ator(*buf);
		i++;
	}
	ft_dyna_append(&cur->vertices, &tmp, 1);
}

static inline void	add_face(char **buf, t_obj *cur)
{
	t_face		tmp;
	size_t		i;

	tmp = (t_face){{0, 0, 0, 0}};
	i = 0;
	while (i < 4)
	{
		next_word(buf);
		tmp.index[i] = ft_atoi(*buf);
		i++;
	}
	ft_dyna_append(&cur->faces, &tmp, 1);
}

int					parse_obj(t_obj *w, int fd)
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
			add_vrtx(&buf, &cur);
		else if (*buf == 'f')
			add_face(&buf, &cur);
	}
	return (0);
}
