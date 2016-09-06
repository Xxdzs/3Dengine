/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 05:09:30 by angagnie          #+#    #+#             */
/*   Updated: 2016/09/06 17:09:47 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

unsigned	perspectiveA(t_env *w, t_pnt2i o, t_pnt2i d, size_t info)
{
	const size_t	n = 2;
	t_pnt2i			p;
	unsigned		ans;

	p.y = d.y >> n;
	while (p.y-- > 0)
	{
		p.x = d.x + 2 * p.y;
		while (p.x-- > 0)
			if ((ans = frac_render(w, (t_pnt2i){p.x, p.y << (n + 1)},
						 (t_pnt2i){d.x + 2 * p.y, d.y + 2 * p.y})))
				pxl_on(w, o.x + p.x - p.y, o.y - p.y, ans);
	}
}

unsigned	perspectiveB(t_env *w, t_pnt2i o, t_pnt2i d, t_fnray f, size_t info)
{
	const size_t	n = 2;
	t_pnt2i			p;
	unsigned		ans;

	p.y = d.y >> n;
	while (p.y-- > 0)
	{
		p.x = d.x + 2 * p.y;
		while (p.x-- > 0)
			if ((ans = f(w, (t_pnt2i){p.x, p.y << n},
						 (t_pnt2i){d.x, d.y})))
				pxl_on(w, o.x + p.x - p.y, o.y - p.y, ans);
	}
}

unsigned	stripesA(t_env *w, t_pnt2i p, t_pnt2i d)
{
	(void)w;
	if (p.x % 7 == p.y % 7 || (p.x - 1) % 7 == p.y % 7)
		return ((120 << 8) + (p.y << 16) + p.x);
	return (0);
}

unsigned	stripesB(t_env *w, t_pnt2i p, t_pnt2i d)
{
	(void)w;
	if (!(p.x % 7) || !((p.x - 1) % 7))
		return ((120 << 8) + (p.y << 16) + p.x);
	return (0);
}

void		local_render(t_env *w, t_pnt2i o, t_pnt2i d, t_fnray f)
{
	t_pnt2i		p;
	unsigned	ans;

	p.y = d.y;
	while (p.y-- > 0)
	{
		p.x = d.x;
		while (p.x-- > 0)
			if ((ans = f(w, p, d)))
				pxl_on(w, o.x + p.x, o.y + p.y, ans);
	}
}

void		place_tile(t_env *w, t_pnt2i o, t_fnray f)
{
	const size_t	c = w->data.tile;
	const size_t	d = (3 * c) / 2;

	w->frc.zoom *= 0.95;
	w->frc.is_julia ^= 1;
	local_render(w, (t_pnt2i){o.x * d + c / 2, o.y * d + c / 2},
		(t_pnt2i){c, c}, frac_render);
	local_render(w, (t_pnt2i){o.x * d + c / 2, o.y * d + c / 2},
		(t_pnt2i){c, c}, stripesA);
	perspectiveA(w, (t_pnt2i){o.x * d + c / 2, o.y * d + c / 2},
		(t_pnt2i){c, c}, 0x1);
	perspectiveB(w, (t_pnt2i){o.x * d + c / 2, o.y * d + c / 2},
		(t_pnt2i){c, c}, &stripesB, 0x1);
}

int			editor_repaint(t_env *w)
{
	t_pnt2i o;

	o.y = 4;
	while (o.y-- > 0)
	{
		o.x = 7;
		while (o.x-- > 0)
			place_tile(w, o, &frac_render);
	}
	return (0);
}
