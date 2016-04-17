/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 18:26:09 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/17 16:29:44 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

void		complx_ensure_carth(t_cmplx *c)
{
	if (c->type == POLAR)
		polar2carth(v);
}

void		complx_ensure_polar(t_cmplx *c)
{
	if (c->type == CARTHESIAN)
		carth2polar(v);
}

t_cmplx		cmplx_log(t_cmplx *c)
{
	ensure_polar(c);
	return (NEW_CMPLX(log(c->p.mod), c->p.arg));
}

t_cmplx		cmplx_cos(t_cmplx *c)
{
	ensure_carth(c);
	return (NEW_CMPLX(cos(c->c.x) * cosh(c->c.y), sin(c->c.x) * sinh(c->c.y)));
}

t_cmplx		cmplx_sin(t_cmplx *c)
{
	ensure_carth(c);
	return (NEW_CMPLX(sin(c->c.x) * cosh(c->c.y), cos(c->c.x) * sinh(c->c.y)));
}

t_real		cmplx_mod(t_cmplx *c)
{
	if (c->type == SPHERICAL)
		return (MOD(*c));
	return (sqrt(X(*c) * X(*c) + Y(*c) * Y(*c) + Z(*c) * Z(*c)));
}

t_real		cmplx_rep(t_cmplx *c)
{
	if (c->type == CARTHESIAN)
		return (REP(*c));
	return (MOD(*c) * sin(ARG(*c)));
}
