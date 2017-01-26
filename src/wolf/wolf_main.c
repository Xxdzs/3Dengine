/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 19:15:59 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/26 17:34:41 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	wolf_init(t_wlf *w)
{
	w->camera.fov = DEFAULT_FOV;
}

/*
** Wolf Main
*/

int		the_main(int ac, char **av)
{
	t_wlf			w[1];
	t_env *const	e = (t_env *)w;

	db_putstr("Wolf_main");
	(void)ac;
	(void)av;
	env_new(e);
//	e->fnct.repaint = &wolf_repaint;
	wolf_init(w);
	ggl_main(e);
	return (0);
}
