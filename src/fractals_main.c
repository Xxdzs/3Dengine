/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 11:48:15 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/12 18:36:21 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

int		frac_submain(t_env *w, int ac, char **av)
{
	(void)ac;
	w->frc.is_julia = 0;
	w->frc.lock = 0;
	w->frc.c = NEW_CMPLX(0.285, 0.01);
	w->frc.f = &cmplx_julia;
	w->frc.cntr = NEW_CMPLX(0, 0);
	w->frc.zoom = 4;
	w->frc.max_iter = 40;
	w->frc.light = 127;
	w->frc.speed = NEW_VEC3(80, 100, 70);
	if (!ft_strcmp(*av, "julia"))
		w->frc.is_julia = 1;
	w->fnct.repaint = &frac_render;
	return (0);
}

int		frac_main(int ac, char **av)
{
	if (!ac || (ft_strcmp("julia", *av) && ft_strcmp("mandelbrot", *av)
		&& ft_strcmp("whatever", *av)))
	{
		ft_putstr("Usage :\t./fractol julia\n\t./fractol mandelbrot\n");
		ft_putstr("\t./fractol whatever\n");
		return (1);
	}
	ggl_main(ac, av, &frac_submain);
	return (0);
}
