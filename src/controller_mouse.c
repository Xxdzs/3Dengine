/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller_mouse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 22:31:25 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/12 22:31:48 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ggl.h"

int				default_mouse_hook(int button, int x, int y, void *param)
{
	t_env *const	w = param;

	ft_putstr("Mouse click : ");
	ft_putnbr(button);
	ft_putstr("\n");
	if (button == 1)
		frac_zoom(w, (t_pnt2i){x, y});
	else if (button == 2)
		w->frc.cntr = frac_transform(w, (t_pnt2i){x, y});
	w->fnct.repaint(w);
	w->fnct.expose(w);
	return (0);
}

int				default_mouse_move_hook(int x, int y, void *param)
{
	t_env *const	w = param;

	if (!w->frc.is_locked)
	{
		w->frc.c = frac_transform(w, (t_pnt2i){x, y});
		w->fnct.repaint(w);
		w->fnct.expose(w);
	}
	return (0);
}
