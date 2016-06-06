/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <sid@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:48:37 by sid               #+#    #+#             */
/*   Updated: 2016/06/07 00:05:53 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"
void				vrtx_offset(t_real *x, t_real *y, t_vrtx *v)
{
	X(v->vec) += *x;
	Y(v->vec) += *y;
}

t_gnode				*obj_adjust(t_obj *o)
{
	const t_vec2i	dim = (t_vec2i){{DEFAULT_RESOLUTION}};
	const t_real	ref = XP(o->dim) < YP(o->dim) ? YP(o->dim) : XP(o->dim);
	const int		rep = dim.c.x > dim.c.y ? dim.c.y : dim.c.x;
	t_real			tmp[2];

	X(o->node.pos) = dim.d.width / 2;
	Z(o->node.pos) = dim.d.height / 2;
	o->node.alpha = 1;
	o->node.gamma = 0.1;
	o->node.scale = rep / (ref + 2);
	tmp[0] = -XP(o->dim) / 2;
	tmp[1] = -YP(o->dim) / 2;
	ft_dyna_iter2(&o->vertices, &vrtx_offset, tmp, tmp + 1);
	return ((t_gnode *)o);
}
