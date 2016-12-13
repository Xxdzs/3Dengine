/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 19:15:59 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/09 19:50:54 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

int		editor_submain(t_env *w, int ac, char **av)
{
	db_putstr("Editor Sub-main");
	frac_submain(w, ac, av);
	w->fnct.repaint = &editor_repaint;
	w->fnct.key_hook = &editor_key_hook;
	w->fnct.mouse_click = &editor_mouse_click;
	w->fnct.mouse_move = &editor_mouse_move;
	init_fnct(w);
	w->draw.color = NEW_COLOR_RGB(100,150,200);
	w->draw.gap = 9;
	w->edit.tile = 256;

	w->frc.is_julia = 0;
	w->frc.is_locked = 1;
	w->frc.zoom = 4;
	w->frc.max_iter = 40;
	w->frc.cntr = NEW_CMPLX(0, 0);
	w->frc.c = NEW_CMPLX(0.285, 0.01);
	w->frc.speed = NEW_VEC3(80, 100, 70);
	return (0);
}

int		wolf_submain(t_env *w, int ac, char **av)
{
	db_putstr("Wolf Sub-main");
	w->draw.gap = 9;
	w->draw.color = NEW_COLOR_RGB(100, 150, 200);
	w->fnct.repaint = &wolf_repaint;
	init_fnct(w);
/*
** if (!(w->wolf.map = (t_cell *)malloc(sizeof(t_cell))))
** ft_exit("wolf_sunmain", "Out of memory (malloc failed)");
*/
	w->wolf.fov = ((t_real)DEFAULT_FOV * M_PI) / 180.;
	w->wolf.width = 2 * SCREEN_DISTANCE * tan(w->wolf.fov);
	return (0);
}

int		wolf_main(int ac, char **av)
{
	t_wolf	w;

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
