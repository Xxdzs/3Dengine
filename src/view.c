/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:01:23 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/06 17:24:41 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "ggl.h"

void		pxl_on(t_env *w, int x, int y, unsigned int color)
{
	char			*t;
	unsigned int	*c;

	if (0 <= x && x < w->wdim.d.width
		&& 0 <= y && y < w->wdim.d.height)
	{
		t = w->pixel + y * w->line_size + x * w->bits_per_pixel / 8;
		c = (unsigned int *)t;
		*c = color;
	}
}

int			draw_line(t_env *const w, t_pnt2i *p1, t_pnt2i *p2)
{
	if (p1->x == p2->x && p1->y == p2->y)
		pxl_on(w, p1->x, p2->y, 200 << 16);
	return (interpolate(w, p1, p2, &linear_interpolation));
}
