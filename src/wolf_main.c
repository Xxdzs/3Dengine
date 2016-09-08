/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 19:15:59 by angagnie          #+#    #+#             */
/*   Updated: 2016/09/08 02:24:00 by angagnie         ###   ########.fr       */
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
	w->draw.color = NEW_COLOR_RGB(200,150,100);
	w->edit.tile = 256;

	w->frc.is_julia = 0;
	w->frc.is_locked = 1;
	w->frc.zoom = 4;
	w->frc.max_iter = 300;
	w->frc.cntr = NEW_CMPLX(0, 0);
	w->frc.c = NEW_CMPLX(0.285, 0.01);
	w->frc.speed = NEW_VEC3(30, 20, 40);
	return (0);
}

int		wolf_submain(t_env *w, int ac, char **av)
{
	db_putstr("Wolf Sub-main");
	frac_submain(w, ac, av);
	return (0);
}

int		the_main(int ac, char **av)
{
	if (ac == 0)
		db_putstr("Missing arguments !!");
	else if (!ft_strcmp("editor", *av))
	{
		db_putstr("Editing campaign :");
		if (ac > 2)
			db_putstr(av[1]);
		else
			db_putstr("Tests");
		ggl_main(ac, av, &editor_submain);
	}
	else
		ggl_main(ac, av, &wolf_submain);
	return (0);
}
