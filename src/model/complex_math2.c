/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 18:54:00 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/13 01:51:54 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"
#include <math.h>

t_cmplx		cmplx_square(const t_cmplx *z)
{
	if (z->type == CARTHESIAN)
		return (NEW_CMPLX(
			(XP(z) + YP(z)) * (XP(z) - YP(z)),
			2 * XP(z) * YP(z)));
		return ((t_cmplx){POLAR, {{
			MODP(z) * MODP(z),
			2 * ARGP(z)}}});
}

t_cmplx		cmplx_prod(t_cmplx *a, t_cmplx *b)
{
	if (a->type == CARTH && b->type == CARTH)
		return (NEW_CMPLX(
			XP(a) * XP(b) - YP(a) * YP(b),
			XP(a) * YP(b) + YP(a) * XP(b)));
		if (a->type == CARTHESIAN)
		carth2polar(a);
	else if (b->type == CARTHESIAN)
		carth2polar(b);
	return ((t_cmplx){POLAR, {{
			MODP(a) * MODP(b),
			ARGP(a) + ARGP(b)
		}}});
}

t_cmplx		cmplx_exp(const t_cmplx *z)
{
	const t_cmplx	tmp = cmplx_cpy(z, CARTHESIAN);

	return (NEW_CMPLX(
			exp(X(tmp)) * cos(Y(tmp)),
			exp(X(tmp)) * sin(Y(tmp))));
}

t_cmplx		cmplx_pow(const t_cmplx *z, const t_real n)
{
	const t_cmplx	tmp = cmplx_cpy(z, POLAR);

	return ((t_cmplx){POLAR, {{
			pow(MOD(tmp), n),
			n * ARG(tmp)
		}}});
}

t_cmplx		cmplx_sinh(const t_cmplx *z)
{
	const t_cmplx		ez = cmplx_exp(z);
	const t_cmplx		mz = NEW_CMPLX(-XP(z), -YP(z));
	const t_cmplx		e_z = cmplx_exp(&mz);

	return (NEW_CMPLX(
			(X(ez) - X(e_z)) / 2,
			(Y(ez) - Y(e_z)) / 2));
}
