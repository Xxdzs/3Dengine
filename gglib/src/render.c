/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 13:32:26 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/01 19:12:54 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "ggl.h"

#include <stdio.h> // <==

#define POINT(i) (((t_vrtx *)ft_dyna_get(&f->vertices, i))->vec.v.c)
#define PROJECT(i) (t_pnt2i){(int)POINT(i).x, (int)POINT(i).z}

int		render(t_env *w)
{
	t_dyna		l;
#ifdef EULER
	t_pnt2i		p[2];
	t_mat3x3	m;
	t_mat3x3	mt;
#else
	t_qtrn		q;
	t_qtrn		r;
#endif
	t_obj		*f = (t_obj *)w->g.world->node.children.root.next;

	ft_bzero(w->pixel, w->wdim.d.width * w->wdim.d.height * w->bits_per_pixel / 8);
	ft_putstr("\t--==  Renderin ");
	ft_putstr(f->name);
	ft_putstr("  ==--\n");
#ifdef EULER
	m = mat_xaxis(w->g.world->node.alpha);
	mt = mat_yaxis(w->g.world->node.beta);
	m = mat_3x3_times_3x3(&m, &mt);
	mt = mat_zaxis(w->g.world->node.gamma);
	m = mat_3x3_times_3x3(&m, &mt);
	l = ft_dyna_new(sizeof(t_vrtx));
	ft_dyna_append(&l, f->vertices.data, f->vertices.chunck_count);
	ft_dyna_iter1(&l, &vrtx_transform, &m);
#endif
	for (size_t i = 0 ; i < f->vertices.chunck_count ; i++)
	{
#ifdef EULER
		if (i % ((unsigned)XP(f->dim) + 1) < (unsigned)trunc(XP(f->dim)))
		{
			*p = PROJECT(i);
			p[1] = PROJECT(i + 1);
			draw_line(w, p, p + 1);
		}
#endif
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
