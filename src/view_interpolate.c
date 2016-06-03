/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:01:23 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/03 10:32:23 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

static int	identity(int i, int dout, int din)
{
	(void)dout;
	(void)din;
	return (i);
}

static int	linear_interpolation(int i, int dout, int din)
{
	return ((i * dout) / din);
}

int			smooth_interpolation(int i, int dout, int din)
{
	const t_real	x = (t_real)i;
	const t_real	out = (t_real)dout;
	const t_real	in = (t_real)din;

	return ((int)(out * (1 - cos(x * M_PI / in)) / 2));
}

int			interpolate(t_env *const w, t_pnt2i *p1, t_pnt2i *p2, t_fnptr algo)
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
	i = (delta.x > delta.y ? delta.x : delta.y) + 1;
	while (i-- > 0)
		pxl_on(w, p1->x + fx(i, delta.x, delta.y) * way.x,
			p1->y + fy(i, delta.y, delta.x) * way.y, 200 << 16);
	return (0);
}
