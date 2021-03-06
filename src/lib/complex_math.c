/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 18:26:09 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/13 01:51:01 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include <math.h>

t_cmplx		cmplx_log(const t_cmplx *c)
{
	const t_cmplx		tmp = cmplx_cpy(c, POLAR);

	return (NEW_CMPLX(log(MOD(tmp)), ARG(tmp)));
}

t_cmplx		cmplx_cos(const t_cmplx *c)
{
	const t_cmplx		tmp = cmplx_cpy(c, CARTHESIAN);

	return (NEW_CMPLX(cos(X(tmp)) * cosh(Y(tmp)), sin(X(tmp)) * sinh(Y(tmp))));
}

t_cmplx		cmplx_sin(const t_cmplx *c)
{
	const t_cmplx		tmp = cmplx_cpy(c, CARTHESIAN);

	return (NEW_CMPLX(sin(X(tmp)) * cosh(Y(tmp)), cos(X(tmp)) * sinh(Y(tmp))));
}

t_real		cmplx_mod(const t_cmplx *c)
{
	if (c->type != CARTHESIAN)
		return (MODP(c));
	return (sqrt(XP(c) * XP(c) + YP(c) * YP(c)));
}

t_real		cmplx_rep(const t_cmplx *c)
{
	if (c->type == CARTHESIAN)
		return (REPP(c));
	return (MODP(c) * sin(ARGP(c)));
}
