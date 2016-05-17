/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 13:32:26 by angagnie          #+#    #+#             */
/*   Updated: 2016/05/17 15:46:04 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

#include <stdio.h> // <==

#define POINT(i) (((t_vrtx *)ft_dyna_get(&f->vertices, i - 1))->vec.v.c)

int		render(t_env *w)
{
	char *tmp; // <--
	t_pnt2i		a;
	t_pnt2i		b = {0, 0};
	t_qtrn		q;
	t_qtrn		r;
	t_obj		*f = (t_obj *)w->g.world->node.children.root.next;

	ft_bzero(w->pixel, w->wdim.d.width * w->wdim.d.height * w->bits_per_pixel / 8);
	ft_putstr("\t--==  Renderin ");
	ft_putstr(f->name);
	ft_putstr("  ==--\n");
	for (size_t i = 0 ; i < f->vertices.chunck_count ; i++)
	{
		r = f->node.rot;
		perso2rqtrn(&r);
		q = NEW_QTRN(POINT(i).x, POINT(i).y, POINT(i).z, 0.0);
		qtrn_external_mult(&q, w->g.world->node.scale);
		printf("Point actuel : %s\n", tmp = qtrn_to_string(&q)); // <--
		free(tmp); // <--
		qtrn_rotate(&q, r);
		a = (t_pnt2i){X(q), Y(q)};
		//PIXEL(a.x, a.y) = 200;
		draw_line(w, &a, &b);
		b = a;
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
