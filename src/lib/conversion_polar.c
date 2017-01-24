/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_polar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 12:32:44 by angagnie          #+#    #+#             */
/*   Updated: 2016/05/31 17:19:19 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include <math.h>

/*
** > Carthesian <
** |  x   y   [z]
** > Polar (Cylindrical) <
** |  module (r)   argument (theta)   (z)
** > Spherical <
** |  rho   theta   phi
*/

/*
** \ < 2D & 3D >
** - Carthesian to Polar & Cylindrical
** - Polar & Cylindrical to Carthesian
** /
** \ < 3D >
** - Carthesian to Spherical
** - Spherical to Carthesian
** |
** - Cylindrical to Spherical
** - Spherical to Cylindrical
** /
** Obvious side effects
*/

void	carth2polar(t_cmplx *v)
{
	const t_real		x = XP(v);
	const t_real		y = YP(v);

	MODP(v) = sqrt(x * x + y * y);
	ARGP(v) = atan2(y, x);
	v->type = POLAR;
}

void	polar2carth(t_cmplx *v)
{
	const t_real		m = MODP(v);
	const t_real		a = ARGP(v);

	XP(v) = m * cos(a);
	YP(v) = m * sin(a);
	v->type = CARTHESIAN;
}

void	carth2cylin(t_vec3t *v)
{
	carth2polar((t_vec2t *)v);
}

void	cylin2carth(t_vec3t *v)
{
	polar2carth((t_vec2t *)v);
}
