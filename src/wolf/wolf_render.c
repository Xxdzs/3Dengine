/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 13:40:09 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/26 17:19:25 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "paint.h"

# define WENV_GET(W) ((W)->super.super)

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
	return (w->map.data + (long)p.y * w->map.dim.d.width + (long)p.x);
}

t_real		raycast(t_wlf *w, t_real a)
{
	(void)w;
	(void)a;
	return (1);
}

void		wlf_column(t_wlf *w, int c)
{
	t_real	sigma;

	sigma = 1 - 2 * (t_real)c / (t_real)WENV_GET(w).img.dim.d.width;
	w->camera.dir = sigma;
	w->camera.omega = tan(w->camera.fov);
}

int			wolf_repaint(t_wlf *w)
{
	int		col;

	col = WENV_GET(w).img.dim.d.width;
	while (col-- > 0)
		wlf_column(w, col);
	return (0);
}
