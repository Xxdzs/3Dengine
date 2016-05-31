/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:04:21 by angagnie          #+#    #+#             */
/*   Updated: 2016/05/31 14:21:53 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "ggl.h"

/*
** Quaternion :: Get the inverse
*/

t_qtrn	qtrn_get_inv(const t_qtrn *const q)
{
	t_qtrn	ans;

	ans = qtrn_get_conj(q);
	qtrn_external_mult(&ans, 1 / qtrn_get_norm(q));
	return (ans);
}

/*
** Quaternion :: Invert
** Side effect on the quaternion
*/

void	qtrn_inv(t_qtrn *const q)
{
	qtrn_conj(q);
	qtrn_external_mult(q, 1 / qtrn_get_norm(q));
}

/*
** Quaternion :: Get the conjugate
*/

t_qtrn	qtrn_get_conj(const t_qtrn *const q)
{
	if (q->type == CARTHESIAN)
		return (NEW_QTRN(-XP(q), -YP(q), -ZP(q), WP(q)));
	else if (q->type == CYLINDRICAL)
		return ((t_qtrn){CYLINDRICAL, {{
			QRP(q), QTHETAP(q) + M_PI, -ZP(q), WP(q)}}});
	else
		return ((t_qtrn){SPHERICAL, {{
			QRHOP(q), QTHETAP(q) + M_PI, QPHIP(q) + M_PI, WP(q)}}});
}

/*
** Quaternion :: Conjugate
** Side effect on the quaternion
*/

void	qtrn_conj(t_qtrn *const q)
{
	if (q->type == CARTHESIAN)
	{
		XP(q) *= -1;
		YP(q) *= -1;
		ZP(q) *= -1;
	}
	else if (q->type == CYLINDRICAL)
	{
		QTHETAP(q) += M_PI;
		ZP(q) *= -1;
	}
	else
	{
		QTHETAP(q) += M_PI;
		QPHIP(q) += M_PI;
	}
}
