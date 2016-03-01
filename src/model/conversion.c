/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 12:32:44 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/01 12:45:42 by sid              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Obvious side effects
*/

void	carth2polar(t_vec2 *v)
{
	float const		x = v->c.x;
	float const		y = v->c.y;

	v->p.mod = sqrt(x * x + y * y);
	v->p.arg = atan2(x, y);
}

void	polar2carth(t_vec2 *v)
{
	float const		m = v->p.mod;

	v->c.x = m * cos(v->p.arg);
	v->c.y = m * sin(v->p.arg);
}

void	carth2cylin(t_vec3 *v)
{
	float const		x = v->c.x;
	float const		y = v->c.y;

	v->cyl.r = sqrt(x * x + y * y);
	v->cyl.theta = atan2(x, y);
}

void	cylin2carth(t_vec3 *v)
{
	float const		r = v->cyl.r;

	v->c.x = r * cos(v->cyl.theta);
	v->c.y = r * sin(v->cyl.theta);
}

/*
** Theta is the azimuth,
** Phi is the inclinaison,
** rho is the norme
*/

void	carth2spher(t_vec3 *v)
{
	float const		x = v->c.x;
	float const		y = v->c.y;
	float const		z = v->c.z;

	v->s.rho = sqrt(x * x + y * y + z * z);
	v->s.phi = acos(z / v->s.rho);
	v->s.theta = atan2(x, y);
}

void	spher2carth(t_vec3 *v)
{
	float const		r = v->s.rho;
	float const		t = v->s.theta;
	float const		p = v->s.phi;

	v->c.x = r * sin(p) * cos(t);
	v->c.y = r * sin(p) * sin(t);
	v->c.z = r * cos(p);
}
