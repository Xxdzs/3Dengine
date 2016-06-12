/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 18:13:34 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/12 16:12:28 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"
/*
** X(z) = ((t_real)p.x) * zoom * w->ratio / ((t_real)w->wdim.d.width) + X(op);
** Y(z) = -((t_real)p.y) * zoom / ((t_real)w->wdim.d.height) + Y(op);
*/
t_cmplx			frac_transform(t_env *w, t_pnt2i	p)
{
	t_cmplx		ans;

	ans.type = CARTHESIAN;
	X(ans) = ((t_real)p.x) * w->frc.zoom * w->ratio
		/ ((t_real)w->wdim.d.width) + X(w->frc.cntr);
	Y(ans) = -((t_real)p.y) * w->frc.zoom
		/ ((t_real)w->wdim.d.height) + Y(w->frc.cntr);
	return (ans);
}

int				frac_render(t_env *w)
{
	t_pnt2i	p;
	t_cmplx	z;
	size_t	iter;
	t_frac	f;

	f = w->frc;
	p.y = w->wdim.d.height;
	while (p.y-- > 0)
	{
		p.x = w->wdim.d.width;
		while (p.x-- > 0)
		{
			z = frac_transform(w, (t_pnt2i){p.x - w->wdim.d.width / 2,
				p.y - w->wdim.d.height / 2});
			if (!f.is_julia)
				f.c = z;
			iter = f.max_iter;
			while (iter-- && cmplx_mod(&z) < 2)
				z = f.f(&z, &f.c);
			pxl_on(w, p.x, p.y, frac_color(f.max_iter - iter,
				f.light));
		}
	}
	return (0);
}

unsigned int	frac_color(size_t ite, t_real lightness)
{
	t_real			tmp;
	unsigned int	ans;

	tmp = lightness * (1 - cos((t_real)ite / 50));
	ans = (unsigned)tmp << 16;
	tmp = lightness * (1 + sin((t_real)ite / 40));
	ans += (unsigned)tmp << 8;
	tmp = lightness * (1 - sin((t_real)ite / 60));
	ans += (unsigned)tmp ;
	return (ans);
}
