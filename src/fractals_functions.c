/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 12:42:57 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/13 00:27:27 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

t_cmplx		cmplx_id(t_cmplx *z)
{
	return (*z);
}

t_cmplx		cmplx_cool(t_cmplx *z)
{
	const t_cmplx	tmp = cmplx_sinh(z);

	return (cmplx_pow(&tmp, 0.5));
}

t_cmplx		frac_julia(t_cmplx *z, t_cmplx *c)
{
	t_cmplx		ans;

	ans = NEW_CMPLX(
		(XP(z) + YP(z)) * (XP(z) - YP(z)) + XP(c),
		2 * XP(z) * YP(z) + YP(c));
	return (ans);
}

t_cmplx		frac_apply(t_cmplx *z, t_cmplx *c, t_real pow, int b)
{
	t_cmplx		ans;
	const void	*fnct[] = {cmplx_id, cmplx_log, cmplx_exp, cmplx_cos,

	cmplx_sin, cmplx_sinh, cmplx_cool};
	ans = cmplx_pow(z, pow);
	polar2carth(&ans);
	ans = ((t_cmplx (*)(t_cmplx *))fnct[b])(&ans);
	X(ans) += XP(c);
	Y(ans) += YP(c);
	return (ans);
}
