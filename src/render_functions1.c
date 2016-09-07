/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_functions1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 20:46:55 by angagnie          #+#    #+#             */
/*   Updated: 2016/09/07 22:39:27 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

unsigned    stripesA(t_env *w, t_pnt2i p, t_pnt2i d)
{
	(void)d;
	if (p.x % w->draw.gap == p.y % w->draw.gap
		|| (p.x - 1) % (2 * w->draw.gap) == p.y % (2 * w->draw.gap)
		|| (p.x + 1) % (3 * w->draw.gap) == p.y % (3 * w->draw.gap))
		return (w->draw.color);
	return (0);
}

unsigned    stripesB(t_env *w, t_pnt2i p, t_pnt2i d)
{
	(void)d;
	if (!(p.x % w->draw.gap)
		|| !((p.x - 1) % 2 * w->draw.gap)
		|| !((p.x + 1) % 3 * w->draw.gap))
		return (w->draw.color);
	return (0);
}

unsigned    stripesC(t_env *w, t_pnt2i p, t_pnt2i d)
{
	if ((((p.x % (d.x >> 2)) * d.y) / d.x) == p.y % (d.y >> 2)
		|| ((((p.x - 1) % (d.x >> 1)) * d.y) / d.x) == p.y % (d.y >> 1)
		|| ((((p.x + 1) % d.x) * d.y) / d.x) == p.y % d.y)
		return (w->draw.color);
	return (0);
}

unsigned    stripesD(t_env *w, t_pnt2i p, t_pnt2i d)
{
	if (!(p.x % (d.x >> 3))
		|| !((p.x - 1) % (d.x >> 2))
		|| !((p.x + 1) % (d.x >> 1)))
		return (w->draw.color);
	return (0);
}
