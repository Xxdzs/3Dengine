/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 12:32:44 by angagnie          #+#    #+#             */
/*   Updated: 2016/05/31 17:18:14 by angagnie         ###   ########.fr       */
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

/*
** Theta is the azimuth,
** Phi is the inclinaison,
** Rho is the norm
*/

void	carth2spher(t_vec3t *v)
{
	const t_real		x = XP(v);
	const t_real		y = YP(v);
	const t_real		z = ZP(v);

	RHOP(v) = sqrt(x * x + y * y + z * z);
	THETAP(v) = atan2(y, x);
	PHIP(v) = acos(z / RHOP(v));
	v->type = SPHERICAL;
}

void	spher2carth(t_vec3t *v)
{
	const t_real		r = RHOP(v);
	const t_real		t = THETAP(v);
	const t_real		p = PHIP(v);

	XP(v) = r * sin(p) * cos(t);
	YP(v) = r * sin(p) * sin(t);
	ZP(v) = r * cos(p);
	v->type = CARTHESIAN;
}

void	cylin2spher(t_vec3t *v)
{
	const t_real		z = ZP(v);
	const t_real		r = RP(v);

	RHOP(v) = sqrt(z * z + r * r);
	PHIP(v) = atan2(r, z);
	v->type = SPHERICAL;
}

void	spher2cylin(t_vec3t *v)
{
	const t_real		rho = RHOP(v);
	const t_real		theta = THETAP(v);

	ZP(v) = cos(theta) * rho;
	RP(v) = sin(theta) * rho;
	v->type = CYLINDRICAL;
}
