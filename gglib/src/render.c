/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 13:32:26 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/01 11:10:33 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "ggl.h"

#include <stdio.h> // <==

#define POINT(i) (((t_vrtx *)ft_dyna_get(&f->vertices, i))->vec.v.c)

int		render(t_env *w)
{
#ifdef EULER
	t_mat3x1	p;
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
	m = mat_xaxis(f->node.alpha);
	mt = mat_yaxis(f->node.beta);
	m = mat_3x3_times_3x3(&m, &mt);
	mt = mat_zaxis(f->node.gamma);
	m = mat_3x3_times_3x3(&m, &mt);
#endif
	for (size_t i = 0 ; i < f->vertices.chunck_count ; i++)
	{
#ifdef EULER
		p = ((t_vrtx *)ft_dyna_get(&f->vertices, i))->vec.v;
		p = mat_3x3_times_3x1(&m, &p);
#else
		r = f->node.rot;
		perso2rqtrn(&r);
		q = NEW_QTRN(POINT(i).x, POINT(i).y, POINT(i).z, 0.0);
		qtrn_rotate(&q, &r);
		a = (t_pnt2i){X(q), Y(q)};
		//PIXEL(a.x, a.y) = 200;
		draw_line(w, &a, &b);
		b = a;
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
