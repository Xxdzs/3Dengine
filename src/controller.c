/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:17:13 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/12 16:54:12 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ggl.h"



static void		part1(int keycode, t_env *w)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_KP_PLUS)
		w->frc.zoom *= 0.8;
	else if (keycode == KEY_KP_MINUS)
		w->frc.zoom *= 1.25;
	else if (keycode == KEY_LEFT)
		X(w->frc.cntr) -= w->frc.zoom / 3;
	else if (keycode == KEY_RIGHT)
		X(w->frc.cntr) += w->frc.zoom / 3;
	else if (keycode == KEY_DOWN)
		Y(w->frc.cntr) -= w->frc.zoom / 3;
	else if (keycode == KEY_UP)
		Y(w->frc.cntr) += w->frc.zoom / 3;
}

static void		part2(int keycode, t_env *w)
{
	if (keycode == KEY_CH_RIGHT)
		w->bonus++;
	else if (keycode == KEY_CH_LEFT)
		w->bonus--;
	else if (keycode == KEY_Q && w->frc.light < 120)
		w->frc.light += 8;
	else if (keycode == KEY_A && w->frc.light > 7)
		w->frc.light -= 8;
	else if (keycode == KEY_MINUS)
		w->frc.max_iter = w->frc.max_iter * 0.8 + 1;
	else if (keycode == KEY_PLUS)
		w->frc.max_iter = w->frc.max_iter * 1.25;

}

int				default_key_hook(int keycode, void *param)
{
	t_env	*const w = param;

	ft_putstr("Key Pressed : ");
	ft_putnbr(keycode);
	ft_putendl("");
	part1(keycode, w);
	part2(keycode, w);
	w->fnct.repaint(w);
	w->fnct.expose(w);
	return (0);
}
