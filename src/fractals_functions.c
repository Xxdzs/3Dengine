/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 12:42:57 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/12 17:06:19 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

t_cmplx		cmplx_square(t_cmplx *z)
{
	if (z->type == CARTHESIAN)
		return (NEW_CMPLX((XP(z) + YP(z)) * (XP(z) - YP(z)),
			2 * XP(z) * YP(z)));
	return ((t_cmplx){POLAR, {{MODP(z) * MODP(z), 2 * ARGP(z)}}});
}

t_cmplx		cmplx_julia(t_cmplx *z, t_cmplx *c)
{
	t_cmplx		ans;

	ans = NEW_CMPLX(
		(XP(z) + YP(z)) * (XP(z) - YP(z)) + XP(c),
		2 * XP(z) * YP(z) + YP(c)
	);
	return (ans);
}

t_cmplx		cmplx_log2(t_cmplx *z, t_cmplx *c)
{
	t_cmplx ans;

	ans = cmplx_cos(z);
	X(ans) += XP(c);
	Y(ans) += YP(c);
	return (ans);
}
