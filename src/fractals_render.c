/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 18:13:34 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/12 13:54:07 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"
/*
** X(z) = ((t_real)p.x) * zoom * w->ratio / ((t_real)w->wdim.d.width) + X(op);
** Y(z) = -((t_real)p.y) * zoom / ((t_real)w->wdim.d.height) + Y(op);
*/
t_cmplx	frac_transform(t_env *w, t_pnt2i	p)
{
	t_cmplx		ans;

	X(ans) = ((t_real)p.x) * w->frc.zoom * w->ratio
		/ ((t_real)w->wdim.d.width) + X(w->frc.cntr);
	Y(ans) = ((t_real)p.y) * w->frc.zoom
		/ ((t_real)w->wdim.d.height) + Y(w->frc.cntr);
}

int		frac_render(t_env *w)
{
	t_pnt2i	p;
	t_cmplx	z;
	size_t	iter;

	p.y = w->wdim.d.height;
	while (p.y-- > 0)
	{
		p.x = w->wdim.d.width;
		while (p.x-- > 0)
		{
			z = frac_transform((t_pnt2i){p.x - w->wdim.d.width / 2,
				p.y - w->wdim.d.height / 2}, p);
			iter = w->frc.max_iter;
			while (iter-- && cmplx_mod(z) < 2)
				z = w->frc.f(&z);
			pxl_on(w, p.x, p.y, frac_color());
		}
	}
	return (0);
}
