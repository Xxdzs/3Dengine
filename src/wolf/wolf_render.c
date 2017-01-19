/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 13:40:09 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/19 12:41:48 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

unsigned	texture_1(t_env *w, t_pnt2i p, t_pnt2i d)
{
	(void)w;
	if (p.y < d.y / 5 || p.y > (4 * d.y) / 5)
		return (NEW_COLOR_RGB(150, 50, 50));
	else if (p.x < d.x / 5 || p.x > (4 * d.x) / 5)
		return (NEW_COLOR_RGB(200, 100, 100));
	return (NEW_COLOR_RGB(200, 210, 200));
}

t_cell		*get_tile_at(t_wlf *w, t_pnt2 p)
{
	return (w->map + (long)p.y * w->mdim.d.width + (long)p.x);
}

t_real		raycast(t_env *w, t_real a)
{
	t_pnt2	s;

	s.y = fmod(a, M_PI) ? tan(a) : -2147483648;
	s.x = fmod(a + M_PI_2, M_PI) ? 1 / s.y : -2147483648;
	return (1.);
}

int			wolf_repaint(t_wlf *w)
{
	t_pnt2i	p;
	t_real	d;

	p.x = w->super.super.wdim.d.width;
	while (p.x-- > 0)
	{
		d = raycast(w, w->dir + w->fov *
			(t_real)p.x / w->super.super.wdim.c.x - w->fov / 2);
		p.y = w->super.super.wdim.d.height;
		while (p.y-- > 0)
		{
			w->fov / w->super.super.ratio;
			w->width / w->super.super.ratio;
			1. / d;
		}
	}
	return (0);
}
