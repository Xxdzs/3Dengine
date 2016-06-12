/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 12:42:57 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/12 22:14:54 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

t_cmplx		frac_julia(t_cmplx *z, t_cmplx *c)
{
	t_cmplx		ans;

	ans = NEW_CMPLX(
		(XP(z) + YP(z)) * (XP(z) - YP(z)) + XP(c),
		2 * XP(z) * YP(z) + YP(c));
	return (ans);
}

t_cmplx		frac_apply(t_cmplx *z, t_cmplx *c, t_real pow, t_fun fnct)
{
	t_cmplx ans;

	ans = cmplx_pow(z, pow);
	ans = fnct(&ans);
	X(ans) += XP(c);
	Y(ans) += YP(c);
	return (ans);
}
