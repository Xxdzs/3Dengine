/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:01:23 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/31 12:54:58 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

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

static int	identity(int i, int dout, int din)
{
	(void)dout;
	(void)din;
	return (i);
}

static inline int	linear_interpolation(int i, int dout, int din)
{
	return ((i * dout) / din);
}

int					smooth_interpolation(int i, int dout, int din)
{
	const t_real	x = (t_real)i;
	const t_real	out = (t_real)dout;
	const t_real	in = (t_real)din;

	return ((int)(out * (1 - cos(x * M_PI / in)) / 2));
}

int		interpolate(t_env *const w, t_pnt2i *p1, t_pnt2i *p2, t_fnptr algo)
{
	t_pnt2i	delta;
 	t_pnt2i	way;
	int		i;
	t_fnptr	fx;
	t_fnptr	fy;

	way.x = (p2->x > p1->x ? 1 : -1);
	way.y = (p2->y > p1->y ? 1 : -1);
	delta.x = abs(p1->x - p2->x);
	delta.y = abs(p1->y - p2->y);
	fx = (delta.x < delta.y ? algo : &identity);
	fy = (delta.x > delta.y ? algo : &identity);
	i = delta.x + 1;
	while (i-- > 0)
		PIXEL(p1->x + fx(i, delta.x, delta.y) * way.x,
			p1->y + fy(i, delta.y, delta.x) * way.y) = 150;
	return (0);
}

int		draw_line(t_env *const w, t_pnt2i *p1, t_pnt2i *p2)
{
	return (interpolate(w, p1, p2, &linear_interpolation));
}

/*
int		draw_line_save(t_env *const w, t_pnt2i *p1, t_pnt2i *p2)
{
	t_real	derr;
	t_real	err;
	t_pnt2i	local;

	if (p1->x == p2->x)
	{
		if (p1->y == p2->y)
			PIXEL(p1->x, p1->y) = 200;
		else
			draw_line(w, p1, p2);
	}
	else
	{
		derr = fabs((double)(p1->y - p2->y) / (double)(p1->x - p2->x));
		err = 0;
		local.y = p1->y;
		local.x = p1->x;
		;
	}
	return (0);
}
*/

int		default_repaint(t_env *const w)
{
	ft_putstr("Repainting, but no custom repainting function provided\n");
	draw_line(w, &(t_pnt2i){100, 100}, &(t_pnt2i){200, 100});
	draw_line(w, &(t_pnt2i){200, 200}, &(t_pnt2i){200, 100});
	draw_line(w, &(t_pnt2i){200, 200}, &(t_pnt2i){100, 200});
	draw_line(w, &(t_pnt2i){100, 100}, &(t_pnt2i){100, 200});
	draw_line(w, &(t_pnt2i){100, 100}, &(t_pnt2i){200, 200});
	draw_line(w, &(t_pnt2i){100, 200}, &(t_pnt2i){200, 100});
	return (0);
}
