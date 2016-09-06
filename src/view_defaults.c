/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:01:23 by angagnie          #+#    #+#             */
/*   Updated: 2016/09/06 02:57:26 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

int			default_expose_hook(void *param)
{
	t_env *const	w = param;

	ft_putstr("Exposing\n");
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	return (0);
}

int			default_repaint(t_env *const w)
{
	ft_putstr("Repainting, but no custom repainting function provided\n");
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

int			raytrace(t_env *const w)
{
	t_pnt2i p;

	p.y = w->wdim.d.height;
	while (p.y-- > 0)
	{
		p.x = w->wdim.d.width;
		while (p.x-- > 0)
			pxl_on(w, p.x, p.y, w->fnct.raytrace(w, p, w->wdim));
	}
	return (0);
}

/*
int			tmp_repaint(t_env *const w)
{
	int		map[][] = {{1, 1, 1, 1},
					   {1, 0, 1, 1},
					   {1, 0, 0, 1},
					   {1, 1, 1, 1}};
	int		sw = 800;
	int		sh = 600;
	int		col;
	t_vec2t	d;
	t_vec2t	p = NEW_VEC2(1, 2);
	t_vec2t	r;
	t_vec2i	m;
	t_real	theta;
	t_real	alpha;

	col = sw;
	while (col-- > 0)
	{
		alpha = ((t_real)col * M_PI) / ((t_real)sw * 3) + theta - M_PI_6;
		X(d) = cos(alpha);
		Y(d) = sin(alpha);
		m.c.x = (int)X(p) / 64;
		m.c.y = (int)Y(p) / 64;
		X(r) =
	}
}
*/
