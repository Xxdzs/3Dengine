/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:01:23 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/15 22:57:57 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

#define PIXEL(X,Y) w->pixel[(Y) * w->line_size + (X) * (w->bits_per_pixel / 8)]

int		default_expose_hook(void *param)
{
	t_env *const	w = param;

	ft_putstr("Exposing\n");
#ifdef X11
	// TODO : Display Image
#else
	mlx_clear_window(w->mlx, w->win);
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
#endif
	return (0);
}

int		draw_line_safe(t_env *const w, t_pnt2i *p1, t_pnt2i *p2)
{
	t_pnt2i		delta;
	t_pnt2i		way;
	int			i;

	way.x = (p1->x < p2->x ? 1 : -1);
	way.y = (p1->y < p2->y ? 1 : -1);
	delta.x = abs(p1->x - p2->x);
	delta.y = abs(p1->y - p2->y);
	i = -1;
	if (delta.x > delta.y)
		while (++i <= delta.x)
			PIXEL(p1->x + i * way.x,
				p1->y + ((i * delta.y) / delta.x) * way.y) = 150;
	else
		while (++i <= delta.y)
			PIXEL(p1->x + ((i * delta.x) / delta.y) * way.x,
				p1->y + i * way.y) = 250;
	return (0);
}

int		draw_line(t_env *const w, t_pnt2i *p1, t_pnt2i *p2)
{
	t_real	derr;
	t_real	err;
	t_pnt2i	local;

	if (p1->x == p2->x)
		return (draw_line_safe(w, p1, p2));
	derr = fabs((double)(p1->y - p2->y) / (double)(p1->x - p2->x));
	err = 0;
	local.y = p1->y;
	local.x = p1->x;
	;
	return (0);
}

int		default_repaint(t_env *const w)
{
	ft_putstr("Repainting, but no custom repainting function provided\n");
	draw_line_safe(w, &(t_pnt2i){100, 100}, &(t_pnt2i){200, 100});
	draw_line_safe(w, &(t_pnt2i){200, 200}, &(t_pnt2i){200, 100});
	draw_line_safe(w, &(t_pnt2i){200, 200}, &(t_pnt2i){100, 200});
	draw_line_safe(w, &(t_pnt2i){100, 100}, &(t_pnt2i){100, 200});
	draw_line_safe(w, &(t_pnt2i){100, 100}, &(t_pnt2i){200, 200});
	draw_line_safe(w, &(t_pnt2i){100, 200}, &(t_pnt2i){200, 100});
	return (0);
}
