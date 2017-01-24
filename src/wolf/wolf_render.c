/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 13:40:09 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/24 18:51:41 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "paint.h"

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

t_real		raycast(t_wlf *w, t_real a)
{
	(void)w;
	(void)a;
	return (1.);
}

int			wolf_repaint(t_wlf *w)
{
	(void)w;
	return (0);
}
