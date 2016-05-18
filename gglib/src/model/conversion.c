/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 12:32:44 by angagnie          #+#    #+#             */
/*   Updated: 2016/05/18 10:40:57 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include <math.h>

/*
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
	THETAP(v) = atan2(r, z);
	v->type = SPHERICAL;
}

void	spher2cylin(t_vec3t	*v)
{
	const t_real		rho = RHOP(v);
	const t_real		theta = THETAP(v);

	ZP(v) = cos(theta) * rho;
	RP(v) = sin(theta) * rho;
	v->type = CYLINDRICAL;
}

/*
** p = a + s * u
** q = cos(a/2) + sin(a/2) * u
*/

t_real	perso2rqtrn(t_qtrn *q)
{
	const t_real	alpha = SCALARP(q) / 2;
	const t_real	scale = VECTORP(q).s.rho;

	SCALARP(q) = cos(alpha / 2);
	VECTORP(q).s.rho = sin(alpha / 2);
	return (scale);
}
