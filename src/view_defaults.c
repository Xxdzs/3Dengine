/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:01:23 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/03 10:31:37 by angagnie         ###   ########.fr       */
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
