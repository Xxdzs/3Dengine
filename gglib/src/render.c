/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 13:32:26 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/14 17:58:03 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

#define POINT(i) (((t_vrtx *)ft_dyna_get(&f->vertices, i - 1))->vec.v.c)

int		render(t_env *w)
{
	t_pnt2i		a;
	t_qtrn		q;
	t_qtrn		r;
	t_obj		*f = (t_obj *)w->g.world->node.children.root.next;

	ft_putstr("\t--==  Renderin ");
	ft_putstr(f->name);
	ft_putstr("  ==--\n");
	for (size_t i = 0 ; i < f->vertices.chunck_count ; i++)
	{
		r = f->node.rot;
		perso2rqtrn(&r);
		q = qtrn_new(POINT(i).x, POINT(i).y, POINT(i).z, 0.0);
		qtrn_rotate(q, f->node.rot);

		a = (t_pnt2i){q->c.x, q->c.y};
		PIXEL(a.x, a.y) = 200;
	}
	return (0);
}

int		render_julia(t_env *w, t_fnptr f)
{
	t_real		zoom = 4;
	t_pnt2i		p = (t_pnt2i){0, 0};
	t_cmplx		c = (t_cmplx){{0.285, 0.01}};
	t_cmplx		z = (t_cmplx){{0, 0}};
	t_cmplx		op = (t_cmplx){{-2, 2}};

	for (p.x = 0 ; p.x < w->wdim.d.width ; p.x++)
		for (p.y = 0 ; p.y < w->wdim.d.height ; p.y++)
		{
			z.c.x = ((t_real)p.x) * zoom * w->ratio / ((t_real)w->wdim.d.width) + op.c.x;
			z.c.y = -((t_real)p.y) * zoom / ((t_real)w->wdim.d.height) + op.c.y;
			if (p.x % 400 == 0 && p.y % 300 == 0)
			{
				ft_putstr("Point Actuel : ( ");
				ft_putnbr(z.c.x);
				ft_putstr(" + ");
				ft_putnbr(z.c.y);
				ft_putstr(".i )\n");
			}
		}
	return (0);
}
