/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 13:32:26 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/21 15:50:15 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

#define POINT(i) (((t_vrtx *)ft_dyna_get(&f->vertices, i - 1))->vec.c)

int		render(t_env *w)
{
	t_pnt2i a, b;
	t_obj	*f = (t_obj *)w->g.world->node.children.root.next;

	ft_putstr(" --==  Renderin ");
	ft_putstr(f->name);
	ft_putstr("  ==--\n");
	for (size_t i = 1 ; i < f->vertices.chunck_count ; i++)
	{
		a = (t_pnt2i){150 + 3 * (int)POINT(i - 1).x
					  + (int)POINT(i - 1).y + (int)POINT(i - 1).z,
			30 + 4 * (int)POINT(i - 1).y - (int)POINT(i - 1).z};
		b = (t_pnt2i){150 + 3 * (int)POINT(i).x
					  + (int)POINT(i).y + (int)POINT(i).z,
			30 + 4 * (int)POINT(i).y - (int)POINT(i).z};
		if (a.x != b.x || a.y != b.y)
			draw_line(w, &a, &b);
	}
	return (0);
}
