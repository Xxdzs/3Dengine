/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 11:48:15 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/13 00:57:04 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

void	frac_reset(t_frac *f)
{
	f->cntr = NEW_CMPLX(0, 0);
	f->zoom = 4;
	f->max_iter = 40;
	f->light = 127;
	f->speed = NEW_VEC3(81, 101, 71);
}

int		frac_submain(t_env *w, int ac, char **av)
{
	(void)ac;
	frac_reset(&w->frc);
	w->frc.is_julia = 0;
	w->frc.is_locked = 0;
	w->frc.is_bonus = 0;
	w->frc.power = 3;
	w->frc.c = NEW_CMPLX(0.285, 0.01);
	if (!ft_strcmp(*av, "julia"))
		w->frc.is_julia = 1;
	if (!ft_strcmp(*av, "whatever"))
		w->frc.is_bonus = 1;
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
