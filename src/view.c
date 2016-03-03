/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:01:23 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/03 16:46:36 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define PIXEL(X,Y) w->pixel[(Y) * w->line_size + (X) * (w->bits_per_pixel / 8)]

int		expose_hook(void *param)
{
	t_env *const	w = param;

	ft_putstr("Exposing\n"); // <--
#ifdef X11

#else
	mlx_clear_window(w->mlx, w->win);
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
#endif
	return (0);
}

void	draw_line(t_env *const w, t_pnt2i *p1, t_pnt2i *p2)
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
				p1->y + ((i * delta.y) / delta.x) * way.y)
				= 150;
	else
		while (++i <= delta.y)
			PIXEL(p1->x + ((i * delta.x) / delta.y) * way.x,
				p1->y + i * way.y)
				= 250;
}

void	repaint(t_env *const w)
{
	ft_putstr("Repainting\n"); // <--
	draw_line(w, &(t_pnt2i){10, 10}, &(t_pnt2i){300, 300});
	draw_line(w, &(t_pnt2i){10, 100}, &(t_pnt2i){300, 300});
	draw_line(w, &(t_pnt2i){100, 10}, &(t_pnt2i){300, 300});
	draw_line(w, &(t_pnt2i){400, 10}, &(t_pnt2i){300, 300});
	draw_line(w, &(t_pnt2i){10, 400}, &(t_pnt2i){300, 300});
	expose_hook(w);
}
