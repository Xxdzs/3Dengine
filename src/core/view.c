/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:01:23 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/26 17:32:40 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"
#include "easings.h"

void		pxl_on(t_img *w, t_pnt2i p, unsigned color)
{
	unsigned char	*t;
	unsigned		*c;

	if (0 <= p.x && p.x < w->dim.d.width
		&& 0 <= p.y && p.y < w->dim.d.width)
	{
		t = (unsigned char *)w->data
			+ p.y * w->line_size + p.x * w->bits_per_pixel / 8;
		c = (unsigned *)t;
		*c = color;
	}
}

void		plot_on(t_img *w, t_brush *b, t_pnt2i p)
{
	int			i;

	i = b->size * b->size;
	while (i-- > 0)
		pxl_on(w, (t_pnt2i){p.x - b->size / 2 + i % b->size,
			p.y - b->size / 2 + i / b->size},
			b->color);
}

int			interpolate(t_img *w, t_brush *b, t_pnt2i p1, t_pnt2i p2)
{
	t_pnt2i delta;
	t_pnt2i way;
	int		i;
	t_fnptr fx;
	t_fnptr fy;

	db_putstr("interpolate");
	way.x = (p2.x > p1.x ? 1 : -1);
	way.y = (p2.y > p1.y ? 1 : -1);
	delta.x = abs(p1.x - p2.x);
	delta.y = abs(p1.y - p2.y);
	fx = (delta.x < delta.y ? b->easing : &identity);
	fy = (delta.x > delta.y ? b->easing : &identity);
	i = (delta.x > delta.y ? delta.x : delta.y) + 1;
	while (i-- > 0)
		pxl_on(w, (t_pnt2i){p1.x + fx(i, delta.x, delta.y) * way.x,
			p1.y + fy(i, delta.y, delta.x) * way.y}, b->color);
	return (0);
}

int			draw_line(t_img *w, t_brush *b, t_pnt2i p1, t_pnt2i p2)
{
	db_putstr("draw_line");
	if (p1.x == p2.x && p1.y == p2.y)
		pxl_on(w, p1, b->color);
	return (interpolate(w, b, p1, p2));
}
