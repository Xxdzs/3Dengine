/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:04:21 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/21 17:19:43 by angagnie         ###   ########.fr       */
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
		WP(q) * h->c.x + XP(q) * h->c.w + q->c.y * h->c.z - q->c.z * h->c.y,
		WP(q) * h->c.y + q->c.y * h->c.w - XP(q) * h->c.z + q->c.z * h->c.x,
		WP(q) * h->c.z + q->c.z * h->c.w + XP(q) * h->c.y - q->c.y * h->c.x,
		WP(q) * h->c.w - XP(q) * h->c.x - q->c.y * h->c.y - q->c.z * h->c.z
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

	qx = WP(q) * h->c.x + XP(q) * h->c.w + q->c.y * h->c.z - q->c.z * h->c.y;
	qy = WP(q) * h->c.y + q->c.y * h->c.w - XP(q) * h->c.z + q->c.z * h->c.x;
	qz = WP(q) * h->c.z + q->c.z * h->c.w + XP(q) * h->c.y - q->c.y * h->c.x;
	WP(q) *= h->c.w;
	WP(q) -= XP(q) * h->c.x + q->c.y * h->c.y + q->c.z * h->c.z;
	XP(q) = qx;
	q->c.y = qy;
	q->c.z = qz;
}

/*
** Quaternion :: Get the inverse
*/

t_qtrn	qtrn_get_inv(const t_qtrn *const q)
{
	const t_real	tmp = (WP(q) * WP(q)

	+ XP(q) * XP(q)
	+ q->c.y * q->c.y
	+ q->c.z * q->c.z);
	return ((t_qtrn){{-XP(q) / tmp, -q->c.y / tmp,
		-q->c.z / tmp, WP(q) / tmp}});
}

/*
** Quaternion :: Invert
** Side effect on the quaternion
*/

void	qtrn_inv(t_qtrn *const q)
{
	const t_real	tmp = WP(q) * WP(q)

	+ XP(q) * XP(q)
	+ q->c.y * q->c.y
	+ q->c.z * q->c.z;
	WP(q) /= tmp;
	XP(q) *= -1 / tmp;
	q->c.y *= -1 / tmp;
	q->c.z *= -1 / tmp;
}

/*
** Quaternion :: Get the conjugate
*/

t_qtrn	qtrn_get_conj(const t_qtrn *const q)
{
	return ((t_qtrn){{-XP(q), -q->c.y, -q->c.z, WP(q)}});
}

/*
** Quaternion :: Conjugate
** Side effect on the quaternion
*/

void	qtrn_conj(t_qtrn *const q)
{
	XP(q) *= -1;
	q->c.y *= -1;
	q->c.z *= -1;
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
