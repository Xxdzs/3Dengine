/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller_mouse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 22:31:25 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/23 22:59:01 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ggl.h"
#include "fractals.h"

int				frac_mouse_click(int button, int x, int y, void *param)
{
	t_frac *const	w = param;

	db_putvalue("Mouse click : ", button, "");
	if (button == 1 || button == 4)
		frac_zoom(w, (t_pnt2i){x, y}, 0.8);
	else if (button == 2 || button == 5)
		frac_zoom(w, (t_pnt2i){x, y}, 1.25);
	else if (button == 3)
		w->cntr = frac_transform(w, (t_pnt2i){x, y}, w->super.wdim.c);
	w->super.fnct.repaint(w);
	w->super.fnct.expose(w);
	return (0);
}

int				frac_mouse_move(int x, int y, void *param)
{
	t_frac *const	w = param;

	if (!w->is_locked)
	{
		w->c = frac_transform(w, (t_pnt2i){x, y}, w->super.wdim.c);
		w->super.fnct.repaint(w);
		w->super.fnct.expose(w);
	}
	return (0);
}
