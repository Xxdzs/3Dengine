/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 13:32:26 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/05 19:53:34 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system_tree.h"
#include "geometry.h"
#include "ggl.h"

#define POINT(i) (((t_vrtx *)ft_dyna_get(&l, i))->vec.v.c)
#define PROJECT(i) (t_pnt2i){(int)POINT(i).x, (int)POINT(i).z}

int		render(t_env *w)
{
	t_dyna		l;
	t_pnt2i		p[2];
	t_mat4x4	m;
	t_obj		*f = (t_obj *)w->g.world->node.children.root.next;

	ft_bzero(w->pixel, w->wdim.d.width * w->wdim.d.height * w->bits_per_pixel / 8);
	ft_putstr("\t--==  Renderin ");
	ft_putstr(f->name);
	ft_putstr("  ==--\n");
	m = mat4_get_transformation((t_gnode *)f);
	l = ft_dyna_new(sizeof(t_vrtx));
	ft_dyna_append(&l, f->vertices.data, f->vertices.chunck_count);
	ft_dyna_iter1(&l, &vrtx_transform, &m);
	for (size_t i = 0 ; i < l.chunck_count ; i++)
	{
		if (i % ((unsigned)XP(f->dim) + 0) < (unsigned)trunc(XP(f->dim) - 1))
		{
			*p = PROJECT(i);
			p[1] = PROJECT(i + 1);
			draw_line(w, p, p + 1);
		}
	}
	return (0);
}

int		render_julia(t_env *w, t_fnptr f)
{
	t_real		zoom = 4;
	t_pnt2i		p = (t_pnt2i){0, 0};
	t_cmplx		c = NEW_CMPLX(0.285, 0.01);
	t_cmplx		z = NEW_CMPLX(0, 0);
	t_cmplx		op = NEW_CMPLX(-2, 2);

	(void)f;
	(void)c;
	for (p.x = 0 ; p.x < w->wdim.d.width ; p.x++)
		for (p.y = 0 ; p.y < w->wdim.d.height ; p.y++)
		{
			X(z) = ((t_real)p.x) * zoom * w->ratio / ((t_real)w->wdim.d.width) + X(op);
			Y(z) = -((t_real)p.y) * zoom / ((t_real)w->wdim.d.height) + Y(op);
			if (p.x % 400 == 0 && p.y % 300 == 0)
			{
				ft_putstr("Point Actuel : ( ");
				ft_putnbr(X(z));
				ft_putstr(" + ");
				ft_putnbr(Y(z));
				ft_putstr(".i )\n");
			}
		}
	return (0);
}
