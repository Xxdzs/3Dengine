/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 12:32:44 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/31 16:54:08 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include <math.h>

/*
** Obvious side effects
*/

void	carth2polar(t_cmplx *v)
{
	const t_real		x = X(v);
	const t_real		y = Y(v);

	MOD(v) = sqrt(x * x + y * y);
	ARG(v) = atan2(x, y);
	v->type = POLAR;
}

void	polar2carth(t_cmplx *v)
{
	const t_real		m = MOD(v);
	const t_real		a = ARG(v);

	X(v) = m * cos(a);
	Y(v) = m * sin(a);
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
** rho is the norme
*/

void	carth2spher(t_vec3t *v)
{
	const t_real		x = X(v);
	const t_real		y = Y(v);
	const t_real		z = Z(v);

	RHO(v) = sqrt(x * x + y * y + z * z);
	THETA(v) = atan2(x, y);
	PHI(v) = acos(z / RHO(v));
	v->type = SPHERICAL;
}

void	spher2carth(t_vec3t *v)
{
	const t_real		r = RHO(v);
	const t_real		t = THETA(v);
	const t_real		p = PHI(v);

	X(v) = r * sin(p) * cos(t);
	Y(v) = r * sin(p) * sin(t);
	Z(v) = r * cos(p);
	v->type = CARTHESIAN;
}

t_real	perso2rqtrn(t_qtrn *q)
{
	const t_real	alpha = SCALAR(q) / 2;
	const t_real	scale = VECTOR(q).s.rho;

	SCALAR(q) = cos(alpha / 2);
	VECTOR(q).s.rho = sin(alpha / 2);
	return (scale);
}
