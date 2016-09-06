/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 05:09:30 by angagnie          #+#    #+#             */
/*   Updated: 2016/09/06 06:44:33 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

int		editor_repaint(t_env *w)
{
	t_pnt2i p;
	t_pnt2i d;

	d = (t_pnt2i){800, 600};
	p.y = d.y;
	while (p.y-- > 0)
	{
		p.x = d.x;
		while (p.x-- > 0)
			pxl_on(w, p.x, p.y, frac_render(w, (t_pnt2i){p.x, p.y}, d));
	}
	return (0);
}
