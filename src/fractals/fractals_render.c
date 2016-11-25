/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 18:13:34 by angagnie          #+#    #+#             */
/*   Updated: 2016/09/12 18:30:17 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

t_cmplx		frac_transform(t_env *w, t_pnt2i p, t_pnt2i d)
{
	t_cmplx		ans;

	ans.type = CARTHESIAN;
	X(ans) = ((t_real)(p.x - d.x / 2)) * w->frc.zoom
		* ((t_real)d.x / (t_real)d.y)
		/ ((t_real)d.x) + X(w->frc.cntr);
	Y(ans) = -((t_real)(p.y - d.y / 2)) * w->frc.zoom
		/ ((t_real)d.y) + Y(w->frc.cntr);
	return (ans);
}

unsigned	frac_render(t_env *w, t_pnt2i p, t_pnt2i d)
{
	t_cmplx	z;
	size_t	iter;
	t_frac	f;

	f = w->frc;
	z = frac_transform(w, p, d);
	if (!f.is_julia)
		f.c = z;
	iter = f.max_iter;
	while (iter-- && X(z) * X(z) + Y(z) * Y(z) < 4)
		if (f.is_bonus)
			z = frac_apply(&z, &f.c, f.power, w->frc.function);
		else
			z = frac_julia(&z, &f.c);
	return (frac_color(f.max_iter - iter, &f));
}

unsigned	frac_color(size_t ite, t_frac *f)
{
	t_real			tmp;
	unsigned int	ans;

	tmp = f->light * (1 - cos((t_real)ite / X(f->speed)));
	ans = (unsigned)tmp << 16;
	tmp = f->light * (1 + sin((t_real)ite / Y(f->speed)));
	ans += (unsigned)tmp << 8;
	tmp = f->light * (1 - sin((t_real)ite / Z(f->speed)));
	ans += (unsigned)tmp;
	return (ans);
}
