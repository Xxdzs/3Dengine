/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 05:09:30 by angagnie          #+#    #+#             */
/*   Updated: 2016/09/06 09:39:16 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"


void	local_render(t_env *w, t_pnt2i o, t_pnt2i d, t_fnray f)
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

void	place_tile(t_env *w, t_pnt2i o, t_fnray f)
{
	const size_t	c = w->data.tile;
	const size_t	d = (3 * c) / 2;

	w->frc.zoom *= 0.95;
	w->frc.is_julia ^= 1;
	local_render(w, (t_pnt2i){o.x * d + c / 2, o.y * d + c / 2},
				 (t_pnt2i){c, c}, f);
}

int		editor_repaint(t_env *w)
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
