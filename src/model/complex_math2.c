/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 18:54:00 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/12 20:19:40 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"
#include <math.h>

t_cmplx		cmplx_square(t_cmplx *z)
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

t_cmplx		cmplx_exp(t_cmplx *z)
{
	return (NEW_CMPLX(
			exp(XP(z)) * cos(YP(z)),
			exp(XP(z)) * sin(YP(z))));
}

t_cmplx		cmplx_pow(t_cmplx *z, t_real n)
{
	const t_cmplx	tmp = cmplx_cpy(z, POLAR);

	return ((t_cmplx){POLAR, {{
			pow(MODP(z), n),
			n * ARGP(z)
		}}});
}
