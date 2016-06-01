/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 13:32:26 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/01 13:13:59 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "ggl.h"

#include <stdio.h> // <==

#define POINT(i) (((t_vrtx *)ft_dyna_get(&f->vertices, i))->vec.v.c)

int		render(t_env *w)
{
	t_pnt2i		h[2] = {{0,0},{0,0}};
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
	printf("(%f, %f)\n", XP(f->dim), YP(f->dim));
#ifdef EULER
	m = mat_xaxis(w->g.world->node.alpha);
	mt = mat_yaxis(w->g.world->node.beta);
	m = mat_3x3_times_3x3(&m, &mt);
	mt = mat_zaxis(w->g.world->node.gamma);
	m = mat_3x3_times_3x3(&m, &mt);
#endif
	for (size_t i = 0 ; i < f->vertices.chunck_count ; i++)
	{
#ifdef EULER
		p = ((t_vrtx *)ft_dyna_get(&f->vertices, i))->vec.v;
		p.c.x = p.c.x * w->g.world->node.scale + X(f->node.pos);
		p.c.y = p.c.y * w->g.world->node.scale + Y(f->node.pos);
		p.c.z = p.c.z * w->g.world->node.scale + Z(f->node.pos);
		p = mat_3x3_times_3x1(&m, &p);
		*h = (t_pnt2i){w->wdim.d.width / 2 + (int)p.c.x,
			  w->wdim.d.height / 2 + (int)p.c.z};
		draw_line(w, h, h+1);
		h[1] = h[0];
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
