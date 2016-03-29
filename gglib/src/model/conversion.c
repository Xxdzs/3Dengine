/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 12:32:44 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/27 18:58:42 by angagnie         ###   ########.fr       */
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

inline void	cylin2carth(t_vec3t *v)
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
	PHI(v) = acos(z / RHO(v));
	THETA(v) = atan2(x, y);
}

void	spher2carth(t_vec3t *v)
{
	const t_real		r = RHO(v);
	const t_real		t = THETA(v);
	const t_real		p = PHI(v);

	X(v) = r * sin(p) * cos(t);
	Y(v) = r * sin(p) * sin(t);
	Z(v) = r * cos(p);
}

t_real	perso2rqtrn(t_qtrn *q)
{
	const t_real	alpha = q->d.s / 2;
	const t_real	scale = q->d.v.s.rho;

	q->d.s = cos(alpha / 2);
	q->d.v.s.rho = sin(alpha / 2);
	return (scale);
}
