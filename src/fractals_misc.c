/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_misc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 17:54:01 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/13 01:27:21 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

void	frac_zoom(t_env *w, t_pnt2i p, t_real zoom)
{
	t_cmplx		z;

	z = frac_transform(w, p);
	w->frc.cntr = z;
	w->frc.zoom *= zoom;
	z = frac_transform(w, p);
	X(w->frc.cntr) += X(w->frc.cntr) - X(z);
	Y(w->frc.cntr) += Y(w->frc.cntr) - Y(z);
}
