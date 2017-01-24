/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:04:21 by angagnie          #+#    #+#             */
/*   Updated: 2016/05/31 14:18:32 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "ggl.h"

/*
** Quaternion :: Get the external product : multiplied by a scalar
*/

t_qtrn	qtrn_external_prod(const t_qtrn *const a, const t_real s)
{
	t_qtrn	ans;

	ans.type = a->type;
	if (a->type == CARTHESIAN)
	{
		X(ans) = XP(a) * s;
		Y(ans) = YP(a) * s;
		Z(ans) = ZP(a) * s;
		W(ans) = WP(a) * s;
	}
	else if (a->type == CYLINDRICAL)
	{
		QR(ans) = QRP(a) * s;
		QTHETA(ans) = QTHETAP(a);
		Z(ans) = ZP(a) * s;
		W(ans) = WP(a) * s;
	}
	else
	{
		QRHO(ans) = QRHOP(a) * s;
		QTHETA(ans) = QTHETAP(a);
		QPHI(ans) = QPHIP(a);
		W(ans) = WP(a) * s;
	}
	return (ans);
}

/*
** Quaternion :: External product : multiply by a scalar
** Side effect on the quaternion
*/

void	qtrn_external_mult(t_qtrn *const a, const t_real s)
{
	if (a->type == CARTHESIAN)
	{
		XP(a) *= s;
		YP(a) *= s;
		ZP(a) *= s;
		WP(a) *= s;
	}
	else if (a->type == CYLINDRICAL)
	{
		QRP(a) *= s;
		ZP(a) *= s;
		WP(a) *= s;
	}
	else
	{
		QRHOP(a) *= s;
		WP(a) *= s;
	}
}

/*
** Quaternion :: Get the product
*/

t_qtrn	qtrn_prod(const t_qtrn *const a, const t_qtrn *const b)
{
	const t_qtrn		q = qtrn_cpy(a, CARTHESIAN);
	const t_qtrn		h = qtrn_cpy(b, CARTHESIAN);

	return (NEW_QTRN(
		X(q) * W(h) + Y(q) * Z(h) - Z(q) * Y(h) + W(q) * X(h),
		-X(q) * Z(h) + Y(q) * W(h) + Z(q) * X(h) + W(q) * Y(h),
		X(q) * Y(h) - Y(q) * X(h) + Z(q) * W(h) + W(q) * Z(h),
		-X(q) * X(h) - Y(q) * Y(h) - Z(q) * Z(h) + W(q) * W(h)));
}

/*
** Quaternion :: Multiply
** Side effect on the first quaternion
*/

void	qtrn_mult(t_qtrn *const a, const t_qtrn *const b)
{
	t_qtrn	tmp;

	tmp = qtrn_prod(a, b);
	*a = qtrn_cpy(&tmp, a->type);
}
