/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 05:09:30 by angagnie          #+#    #+#             */
/*   Updated: 2016/09/12 19:25:28 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

void		perspective_frac(t_env *w, t_pnt2i o, t_pnt2i d)
{
	const size_t	n = 2;
	t_pnt2i			p;

	p.y = d.y >> n;
	while (p.y-- > 0)
	{
		p.x = d.x + 2 * p.y;
		while (p.x-- > 0)
			pxl_on(w, o.x + p.x - p.y, o.y - p.y,
				frac_render(w, (t_pnt2i){p.x, p.y << (n + 1)},
					(t_pnt2i){d.x + 2 * p.y, d.y + 2 * p.y}));
	}
}

void		perspective(t_env *w, t_pnt2i o, t_pnt2i d, t_fnray f)
{
	const size_t	n = 2;
	t_pnt2i			p;

	p.y = d.y >> n;
	while (p.y-- > 0)
	{
		p.x = d.x + 2 * p.y;
		while (p.x-- > 0)
			pxl_on(w, o.x + p.x - p.y, o.y - p.y,
				   f(w, (t_pnt2i){p.x, p.y << n}, (t_pnt2i){d.x, d.y}));
	}
}

void		local_render(t_env *w, t_pnt2i o, t_pnt2i d, t_fnray f)
{
	t_pnt2i		p;

	p.y = d.y;
	while (p.y-- > 0)
	{
		p.x = d.x;
		while (p.x-- > 0)
			pxl_on(w, o.x + p.x, o.y + p.y, f(w, o, d));
	}
}

void		place_tile(t_env *w, t_pnt2i o, t_fnray f)
{
	const size_t	c = w->edit.tile;
	const size_t	d = (3 * c) / 2;

	w->frc.zoom *= 0.95;
	w->frc.is_julia ^= 1;
	local_render(w, (t_pnt2i){o.x * d + c / 2, o.y * d + c / 2},
		(t_pnt2i){c, c}, f);
	local_render(w, (t_pnt2i){o.x * d + c / 2, o.y * d + c / 2},
		(t_pnt2i){c, c}, &stripesD);
	perspective_frac(w, (t_pnt2i){o.x * d + c / 2, o.y * d + c / 2},
		(t_pnt2i){c, c});
	perspective(w, (t_pnt2i){o.x * d + c / 2, o.y * d + c / 2},
		(t_pnt2i){c, c}, &stripesD);
}

int			editor_repaint(t_env *w)
{
	t_pnt2i o;

	o.y = 3;
	while (o.y-- > 0)
	{
		o.x = 3;
		while (o.x-- > 0)
			place_tile(w, o, &frac_render);
	}
	return (0);
}
