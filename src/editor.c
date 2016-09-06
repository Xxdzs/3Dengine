/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 05:09:30 by angagnie          #+#    #+#             */
/*   Updated: 2016/09/06 08:31:30 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"



int		editor_repaint(t_env *w)
{
	t_pnt2i p;
	t_pnt2i d;

	d = (t_pnt2i){w->data.tile, w->data.tile};
	p.y = d.y;
	while (p.y-- > 0)
	{
		p.x = d.x;
		while (p.x-- > 0)
			pxl_on(w, d.x + p.x, d.y + p.y,
			frac_render(w, p, d));
	}
	size_t n = 2;
	p.x = d.x >> n;
	while (p.x > 0)
	{
		p.y = d.y + (p.x << 1);
		while (p.y-- > 0)
			pxl_on(w, 2*d.x + p.x, d.y + p.y - p.x,
				frac_render(w, (t_pnt2i){p.x << n, p.y},
					(t_pnt2i){d.x, d.y + (p.x << 1)}));
		p.x--;
	}
	return (0);
}
