/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:01:23 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/24 05:41:38 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "ggl.h"

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
		pxl_on(w, p.x - b->size / 2 + i % b->size,
			p.y - b->size / 2 + i / b->size,
			b->color);
	return (0);
}

int			draw_line(t_img *w, t_brush *b, t_pnt2i p1, t_pnt2i p2)
{
	if (p1->x == p2->x && p1->y == p2->y)
		pxl_on(w, p1, b->color);
	return (interpolate(w, b, p1, p2));
}
