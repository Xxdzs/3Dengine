/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_misc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 17:54:01 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/12 18:27:05 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

void	frac_zoom(t_env *w, t_pnt2i p)
{
	t_cmplx		z;

	z = frac_transform(w, p);
	X(w->frc.cntr) = X(z);
	Y(w->frc.cntr) = Y(z);
	w->frc.zoom *= 0.7;
	z = frac_transform(w, p);
	X(w->frc.cntr) += X(w->frc.cntr) - X(z);
	Y(w->frc.cntr) += Y(w->frc.cntr) - Y(z);
}
