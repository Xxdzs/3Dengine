/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller_mouse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 22:31:25 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/09 14:57:26 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ggl.h"

int				default_mouse_hook(int button, int x, int y, void *param)
{
	t_env *const	w = param;

	(void)x;
	(void)y;
	db_putvalue("Mouse click : ", button, "");
	w->fnct.repaint(w);
	w->fnct.expose(w);
	return (0);
}

int				default_mouse_move_hook(int x, int y, void *param)
{
	(void)x;
	(void)y;
	(void)param;
	return (0);
}
