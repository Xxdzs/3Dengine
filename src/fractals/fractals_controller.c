/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:17:13 by angagnie          #+#    #+#             */
/*   Updated: 2016/09/08 02:02:30 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ggl.h"

static void		part1(int keycode, t_env *w)
{
	if (keycode == KEY_ESC)
		exit(destroy_env(w));
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
	else if (keycode == KEY_MINUS)
		w->frc.max_iter = w->frc.max_iter * 0.8 + 1;
	else if (keycode == KEY_PLUS)
		w->frc.max_iter = w->frc.max_iter * 1.25;
	else if (keycode == KEY_0)
		w->frc.max_iter = 20;
	else if (keycode == KEY_9)
		w->frc.max_iter = 600;
	else if (keycode == KEY_DELETE)
		frac_reset(&w->frc);
}

static void		part2(int keycode, t_env *w)
{
	if (keycode == KEY_CH_RIGHT && w->frc.function < 6)
		w->frc.function++;
	else if (keycode == KEY_CH_LEFT && w->frc.function > 0)
		w->frc.function--;
	else if (keycode == KEY_Q && w->frc.light < 120)
		w->frc.light += 8;
	else if (keycode == KEY_A && w->frc.light > 7)
		w->frc.light -= 8;
	else if (keycode == KEY_W)
		X(w->frc.speed) += 10;
	else if (keycode == KEY_S)
		X(w->frc.speed) -= 10;
	else if (keycode == KEY_E)
		Y(w->frc.speed) += 10;
	else if (keycode == KEY_D)
		Y(w->frc.speed) -= 10;
	else if (keycode == KEY_R)
		Z(w->frc.speed) += 10;
	else if (keycode == KEY_F)
		Z(w->frc.speed) -= 10;
	else if (keycode == KEY_L)
		w->frc.is_locked ^= 1;
	else if (keycode == KEY_J)
		w->frc.is_julia ^= 1;
}

static void		part3(int keycode, t_env *w)
{
	if (keycode == KEY_PG_UP)
		w->frc.power++;
	else if (keycode == KEY_PG_DOWN)
		w->frc.power--;
	else if (keycode == KEY_KP_STAR)
		w->frc.power += 0.1;
	else if (keycode == KEY_KP_SLASH)
		w->frc.power -= 0.1;
	else if (keycode == KEY_KP_EQUAL)
		w->frc.power = 2;
}

int				frac_key_hook(int keycode, void *param)
{
	t_env	*const w = param;

	part1(keycode, w);
	part2(keycode, w);
	part3(keycode, w);
	w->fnct.repaint(w);
	w->fnct.expose(w);
	return (0);
}
