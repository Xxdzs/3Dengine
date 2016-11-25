/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller_mouse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 22:31:25 by angagnie          #+#    #+#             */
/*   Updated: 2016/09/08 00:47:43 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ggl.h"

int				frac_mouse_click(int button, int x, int y, void *param)
{
	t_env *const	w = param;

	db_putvalue("Mouse click : ", button, "");
	if (button == 1 || button == 4)
		frac_zoom(w, (t_pnt2i){x, y}, 0.8);
	else if (button == 2 || button == 5)
		frac_zoom(w, (t_pnt2i){x, y}, 1.25);
	else if (button == 3)
		w->frc.cntr = frac_transform(w, (t_pnt2i){x, y}, w->wdim.c);
	w->fnct.repaint(w);
	w->fnct.expose(w);
	return (0);
}

int				frac_mouse_move(int x, int y, void *param)
{
	t_env *const	w = param;

	if (!w->frc.is_locked)
	{
		w->frc.c = frac_transform(w, (t_pnt2i){x, y}, w->wdim.c);
		w->fnct.repaint(w);
		w->fnct.expose(w);
	}
	return (0);
}
