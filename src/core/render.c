/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 13:32:26 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/18 20:25:42 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system_tree.h"
#include "geometry.h"
#include "ggl.h"

//#define POINT(i) ARRAY_GETT(t_vrtx, )
//#define POINT(i) (((t_vrtx *)ft_dyna_get(&l, i))->vec.v.c)
//#define PROJECT(i) (t_pnt2i){(int)POINT(i).x, (int)POINT(i).z}

const t_obj				*get_vertices(t_env *w, t_array *l)
{
	t_mat4x4		m;
	const t_obj		*f = (t_obj *)w->g.world->node.children.root.next;

	m = mat4_get_transformation((t_gnode *)f);
	*l = NEW_ARRAY(t_vrtx);
	fta_append(l, f->vertices.data, f->vertices.size);
	fta_iter1(l, &vrtx_transform, &m);
	return (f);
}

int					render(t_env *w)
{
	(void)w;
	// :(
	return (0);
}
