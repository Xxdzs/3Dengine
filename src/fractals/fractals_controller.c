/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:17:13 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/23 22:57:12 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ggl.h"
#include "fractals.h"

static void		part1(int keycode, t_frac *w)
{
	if (keycode == KEY_ESC)
		exit(destroy_env((t_env *)w));
	else if (keycode == KEY_KP_PLUS)
		w->zoom *= 0.8;
	else if (keycode == KEY_KP_MINUS)
		w->zoom *= 1.25;
	else if (keycode == KEY_LEFT)
		X(w->cntr) -= w->zoom / 3;
	else if (keycode == KEY_RIGHT)
		X(w->cntr) += w->zoom / 3;
	else if (keycode == KEY_DOWN)
		Y(w->cntr) -= w->zoom / 3;
	else if (keycode == KEY_UP)
		Y(w->cntr) += w->zoom / 3;
	else if (keycode == KEY_MINUS)
		w->max_iter = w->max_iter * 0.8 + 1;
	else if (keycode == KEY_PLUS)
		w->max_iter = w->max_iter * 1.25;
	else if (keycode == KEY_0)
		w->max_iter = 20;
	else if (keycode == KEY_9)
		w->max_iter = 600;
	else if (keycode == KEY_DELETE)
		frac_reset(w);
}

static void		part2(int keycode, t_frac *w)
{
	if (keycode == KEY_CH_RIGHT && w->function < 6)
		w->function++;
	else if (keycode == KEY_CH_LEFT && w->function > 0)
		w->function--;
	else if (keycode == KEY_Q && w->light < 120)
		w->light += 8;
	else if (keycode == KEY_A && w->light > 7)
		w->light -= 8;
	else if (keycode == KEY_W)
		X(w->speed) += 10;
	else if (keycode == KEY_S)
		X(w->speed) -= 10;
	else if (keycode == KEY_E)
		Y(w->speed) += 10;
	else if (keycode == KEY_D)
		Y(w->speed) -= 10;
	else if (keycode == KEY_R)
		Z(w->speed) += 10;
	else if (keycode == KEY_F)
		Z(w->speed) -= 10;
	else if (keycode == KEY_L)
		w->is_locked ^= 1;
	else if (keycode == KEY_J)
		w->is_julia ^= 1;
}

static void		part3(int keycode, t_frac *w)
{
	if (keycode == KEY_PG_UP)
		w->power++;
	else if (keycode == KEY_PG_DOWN)
		w->power--;
	else if (keycode == KEY_KP_STAR)
		w->power += 0.1;
	else if (keycode == KEY_KP_SLASH)
		w->power -= 0.1;
	else if (keycode == KEY_KP_EQUAL)
		w->power = 2;
}

int				frac_key_hook(int keycode, void *param)
{
	t_frac	*const w = param;

	part1(keycode, w);
	part2(keycode, w);
	part3(keycode, w);
	w->super.fnct.repaint(w);
	w->super.fnct.expose(w);
	return (0);
}
