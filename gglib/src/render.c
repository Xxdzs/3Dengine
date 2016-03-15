/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 13:32:26 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/16 00:41:42 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

#define POINT(i) (((t_vrtx *)ft_dyna_get(f->vertices, i - 1))->vec.c)

int		render(t_env *w)
{
	t_obj	*f = (t_obj *)w->g.world->node.children.root.next;

	for (size_t i = 1 ; i < f->vertices.chunck_count ; i++)
	{
		draw_line_safe(w,
					   &(t_pnt2i){150 + POINT(i - 1).x, 300 + POINT(i - 1).y - POINT(i - 1).z},
					   &(t_pnt2i){150 + POINT(i).x, 300 + POINT(i).y - POINT(i).z});
	}
	return (0);
}
