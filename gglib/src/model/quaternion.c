/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:04:21 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/21 17:24:58 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

/*
** Quaternion :: Constructors
*/

t_qtrn	qtrn_new(const t_real a, const t_real b, const t_real c, const t_real d)
{
	return (NEW_QTRN(a, b, c, d));
}

t_qtrn	*qtrn_alloc(const t_real a, const t_real b,
	const t_real c, const t_real d)
{
	t_qtrn	*ans;

	if (!(ans = (t_qtrn *)malloc(sizeof(t_qtrn))))
		return (NULL);
	*ans = NEW_QTRN(a, b, c, d);
	return (ans);
}

/*
** Quaternion :: Get the sum
*/

t_qtrn	qtrn_sum(const t_qtrn *a, const t_qtrn *b)
{
	return (NEW_QTRN(
		XP(a) + XP(b),
		YP(a) + YP(b),
		ZP(a) + ZP(b),
		WP(a) + WP(b)
	));
}

/*
** Quaternion :: Add
** Side effect on the first quaternion
*/

void	qtrn_add(t_qtrn *const a, const t_qtrn *const b)
{
	int i;

	i = 4;
	while (i-- > 0)
		a->v.m[i] += b->v.m[i];
}

/*
** Quaternion :: Get the product
*/

t_qtrn	qtrn_prod(const t_qtrn *const q, const t_qtrn *const h)
{
	return ((t_qtrn){{
		WP(q) * XP(h) + XP(q) * WP(h) + YP(q) * ZP(h) - ZP(q) * YP(h),
		WP(q) * YP(h) + YP(q) * WP(h) - XP(q) * ZP(h) + ZP(q) * XP(h),
		WP(q) * ZP(h) + ZP(q) * WP(h) + XP(q) * YP(h) - YP(q) * XP(h),
		WP(q) * WP(h) - XP(q) * XP(h) - YP(q) * YP(h) - ZP(q) * ZP(h)
		}});
}

/*
** Quaternion :: Multiply
** Side effect on the first quaternion
*/

void	qtrn_mult(t_qtrn *const q, const t_qtrn *const h)
{
	t_real qx;
	t_real qy;
	t_real qz;

	qx = WP(q) * XP(h) + XP(q) * WP(h) + YP(q) * ZP(h) - ZP(q) * YP(h);
	qy = WP(q) * YP(h) + YP(q) * WP(h) - XP(q) * ZP(h) + ZP(q) * XP(h);
	qz = WP(q) * ZP(h) + ZP(q) * WP(h) + XP(q) * YP(h) - YP(q) * XP(h);
	WP(q) *= WP(h);
	WP(q) -= XP(q) * XP(h) + YP(q) * YP(h) + ZP(q) * ZP(h);
	XP(q) = qx;
	YP(q) = qy;
	ZP(q) = qz;
}

/*
** Quaternion :: Get the inverse
*/

t_qtrn	qtrn_get_inv(const t_qtrn *const q)
{
	const t_real	tmp = (WP(q) * WP(q)

	+ XP(q) * XP(q)
	+ YP(q) * YP(q)
	+ ZP(q) * ZP(q));
	return ((t_qtrn){{-XP(q) / tmp, -YP(q) / tmp,
		-ZP(q) / tmp, WP(q) / tmp}});
}

/*
** Quaternion :: Invert
** Side effect on the quaternion
*/

void	qtrn_inv(t_qtrn *const q)
{
	const t_real	tmp = WP(q) * WP(q)

	+ XP(q) * XP(q)
	+ YP(q) * YP(q)
	+ ZP(q) * ZP(q);
	WP(q) /= tmp;
	XP(q) *= -1 / tmp;
	YP(q) *= -1 / tmp;
	ZP(q) *= -1 / tmp;
}

/*
** Quaternion :: Get the conjugate
*/

t_qtrn	qtrn_get_conj(const t_qtrn *const q)
{
	return ((t_qtrn){{-XP(q), -YP(q), -ZP(q), WP(q)}});
}

/*
** Quaternion :: Conjugate
** Side effect on the quaternion
*/

void	qtrn_conj(t_qtrn *const q)
{
	XP(q) *= -1;
	YP(q) *= -1;
	ZP(q) *= -1;
}

/*
** Apply the rotation
** f :	H x H	-> H
**		(q, p)	|-> q * p * inv(q)
*/

t_qtrn	qtrn_get_rotated(const t_qtrn *const to_rotate, t_qtrn rotator)
{
	t_qtrn	ans;

	ans = qtrn_prod(&rotator, to_rotate);
	qtrn_inv(&rotator);
	qtrn_mult(&ans, &rotator);
	return (ans);
}

void	qtrn_rotate(t_qtrn *const to_rotate, t_qtrn rotator)
{
	t_qtrn	ans;

	ans = qtrn_get_inv(&rotator);
	qtrn_mult(to_rotate, &ans);
	qtrn_mult(&rotator, to_rotate);
	ft_memcpy(to_rotate, &rotator, sizeof(ans));
}
