/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller_mouse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 22:31:25 by angagnie          #+#    #+#             */
/*   Updated: 2016/09/06 08:32:15 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ggl.h"

int				editor_mouse_click(int button, int x, int y, void *param)
{
	t_env *const	w = param;

	(void)x;
	(void)y;
	ft_putstr("Mouse click : ");
	ft_putnbr(button);
	ft_putstr("\n");
	if (button == 1 || button == 4)
		;
	else if (button == 2 || button == 5)
		;
	else if (button == 3)
		;
	w->fnct.repaint(w);
	w->fnct.expose(w);
	return (0);
}

int				editor_mouse_move(int x, int y, void *param)
{
	t_env *const	w = param;

	(void)w;
	(void)x;
	(void)y;
	return (0);
}
