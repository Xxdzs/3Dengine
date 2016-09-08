/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:01:23 by angagnie          #+#    #+#             */
/*   Updated: 2016/09/08 02:20:51 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

int			default_expose_hook(void *param)
{
	t_env *const	w = param;

	db_putstr("Exposing");
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	return (0);
}

int			default_repaint(t_env *const w)
{
	db_putstr("Repainting, but no custom repainting function provided");
	interpolate(w, &(t_pnt2i){100, 100}, &(t_pnt2i){400, 200},
		&smooth_interpolation);
	interpolate(w, &(t_pnt2i){400, 300}, &(t_pnt2i){100, 400},
		&smooth_interpolation);
	interpolate(w, &(t_pnt2i){100, 100}, &(t_pnt2i){400, 300},
		&smooth_interpolation);
	interpolate(w, &(t_pnt2i){100, 400}, &(t_pnt2i){400, 200},
		&smooth_interpolation);
	draw_line(w, &(t_pnt2i){120, 400}, &(t_pnt2i){400, 350});
	draw_line(w, &(t_pnt2i){400, 350}, &(t_pnt2i){400, 150});
	draw_line(w, &(t_pnt2i){400, 150}, &(t_pnt2i){125, 100});
	return (0);
}

int			raytrace(void *param)
{
	t_pnt2i p;
	t_env *w;

	w = (t_env *)param;
	p.y = w->wdim.d.height;
	while (p.y-- > 0)
	{
		p.x = w->wdim.d.width;
		while (p.x-- > 0)
			pxl_on(w, p.x, p.y, w->fnct.raytrace(w, p, w->wdim));
	}
	return (0);
}
