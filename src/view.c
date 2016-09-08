/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:01:23 by angagnie          #+#    #+#             */
/*   Updated: 2016/09/08 01:46:20 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "ggl.h"

void		pxl_on(t_env *w, int x, int y, unsigned int color)
{
	unsigned char	*t;
	unsigned int	*c;

	if (0 <= x && x < w->wdim.d.width
		&& 0 <= y && y < w->wdim.d.height)
	{
		t = (unsigned char *)w->pixel
			+ y * w->line_size + x * w->bits_per_pixel / 8;
		c = (unsigned int *)t;
		*c = color;
	}
}

int			plot_on(t_env *w, int x, int y, int c)
{
	int			i;

	i = c * c;
	while (i-- > 0)
		pxl_on(w, x - c / 2 + i % c, y - c / 2 + i / c, 200 << 8);
	return (0);
}

int			draw_line(t_env *const w, t_pnt2i *p1, t_pnt2i *p2)
{
	if (p1->x == p2->x && p1->y == p2->y)
		pxl_on(w, p1->x, p2->y, 200 << 16);
	if (w->draw.line_style == 1)
		return (interpolate(w, p1, p2, &smooth_interpolation));
	else if (w->draw.line_style == 2)
		return (interpolate(w, p1, p2, &ez_interpolation));
	else if (w->draw.line_style == 3)
	{
		plot_on(w, p1->x, p1->y, 3);
		return (plot_on(w, p2->x, p2->y, 3));
	}
	else if (w->draw.line_style == 4)
	{
		plot_on(w, p1->x, p1->y, 5);
		return (plot_on(w, p2->x, p2->y, 5));
	}
	else if (w->draw.line_style == 5)
	{
		plot_on(w, p1->x, p1->y, 7);
		return (plot_on(w, p2->x, p2->y, 7));
	}
	return (interpolate(w, p1, p2, &linear_interpolation));
}
