/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 19:15:59 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/19 12:58:11 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		editor_submain(t_env *e, int ac, char **av)
{
	t_edtr *const w = (t_edtr *)e;

	db_putstr("Editor Sub-main");
	frac_submain(&w->super, ac, av);
	e->fnct.repaint = &editor_repaint;
	e->fnct.key_hook = &editor_key_hook;
	e->fnct.mouse_click = &editor_mouse_click;
	e->fnct.mouse_move = &editor_mouse_move;
	init_fnct(w);
	e->draw.color = NEW_COLOR_RGB(100,150,200);
	e->draw.gap = 9;
	w->tile = 256;

	w->super.is_julia = 0;
	w->super.is_locked = 1;
	w->super.zoom = 4;
	w->super.max_iter = 40;
	w->super.cntr = NEW_CMPLX(0, 0);
	w->super.c = NEW_CMPLX(0.285, 0.01);
	w->super.speed = NEW_VEC3(80, 100, 70);
	return (0);
}

int		wolf_submain(t_env *e, int ac, char **av)
{
	t_wlf *const w = (t_wlf *)e;

	db_putstr("Wolf Sub-main");
	e->draw.gap = 9;
	e->draw.color = NEW_COLOR_RGB(100, 150, 200);
	e->fnct.repaint = &wolf_repaint;
	init_fnct(w);
/*
** if (!(w->wolf.map = (t_cell *)malloc(sizeof(t_cell))))
** ft_exit("wolf_sunmain", "Out of memory (malloc failed)");
*/
	w->fov = ((t_real)DEFAULT_FOV * M_PI) / 180.;
	w->width = 2 * SCREEN_DISTANCE * tan(w->fov);
	return (0);
}

int		wolf_main(int ac, char **av)
{
	t_wlf	w;

	if (ac == 0)
		db_putstr("Missing arguments !!");
	else if (!ft_strcmp("editor", *av))
	{
		db_putstr("Editing campaign :");
		if (ac > 2)
			db_putstr(av[1]);
		else
			db_putstr("Tests");
		ggl_main((t_env *)&w, ac, av, &editor_submain);
	}
	else
		ggl_main((t_env *)&w, ac, av, &wolf_submain);
	return (0);
}
