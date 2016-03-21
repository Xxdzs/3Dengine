/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:04:21 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/21 11:12:09 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

/*
** Quaternion :: Constructor
*/

t_qtrn	qtrn_new(const t_real a, const t_real b, const t_real c, const t_real d)
{
	return ((t_qtrn){{a, b, c, d}});
}

/*
** Quaternion :: Get the sum
*/

t_qtrn	qtrn_sum(const t_qtrn *a, const t_qtrn *b)
{
	return ((t_qtrn){{
		a->c.x + b->c.x,
		a->c.y + b->c.y,
		a->c.z + b->c.z,
		a->c.w + b->c.w
		}});
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
		a->m[i] += b->m[i];
}

/*
** Quaternion :: Get the product
*/

t_qtrn	qtrn_prod(const t_qtrn *const q, const t_qtrn *const h)
{
	return ((t_qtrn){{
		q->c.w * h->c.x + q->c.x * h->c.w + q->c.y * h->c.z - q->c.z * h->c.y,
		q->c.w * h->c.y + q->c.y * h->c.w - q->c.x * h->c.z + q->c.z * h->c.x,
		q->c.w * h->c.z + q->c.z * h->c.w + q->c.x * h->c.y - q->c.y * h->c.x,
		q->c.w * h->c.w - q->c.x * h->c.x - q->c.y * h->c.y - q->c.z * h->c.z
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

	qx = q->c.w * h->c.x + q->c.x * h->c.w + q->c.y * h->c.z - q->c.z * h->c.y;
	qy = q->c.w * h->c.y + q->c.y * h->c.w - q->c.x * h->c.z + q->c.z * h->c.x;
	qz = q->c.w * h->c.z + q->c.z * h->c.w + q->c.x * h->c.y - q->c.y * h->c.x;
	q->c.w *= h->c.w;
	q->c.w -= q->c.x * h->c.x + q->c.y * h->c.y + q->c.z * h->c.z;
	q->c.x = qx;
	q->c.y = qy;
	q->c.z = qz;
}

/*
** Quaternion :: Get the inverse
*/

t_qtrn	qtrn_get_inv(const t_qtrn *const q)
{
	const t_real	tmp = (q->c.w * q->c.w

	+ q->c.x * q->c.x
	+ q->c.y * q->c.y
	+ q->c.z * q->c.z);
	return ((t_qtrn){{-q->c.x / tmp, -q->c.y / tmp,
		-q->c.z / tmp, q->c.w / tmp}});
}

/*
** Quaternion :: Invert
** Side effect on the quaternion
*/

void	qtrn_inv(t_qtrn *const q)
{
	const t_real	tmp = q->c.w * q->c.w

	+ q->c.x * q->c.x
	+ q->c.y * q->c.y
	+ q->c.z * q->c.z;
	q->c.w /= tmp;
	q->c.x *= -1 / tmp;
	q->c.y *= -1 / tmp;
	q->c.z *= -1 / tmp;
}

/*
** Quaternion :: Get the conjugate
*/

t_qtrn	qtrn_get_conj(const t_qtrn *const q)
{
	return ((t_qtrn){{-q->c.x, -q->c.y, -q->c.z, q->c.w}});
}

/*
** Quaternion :: Conjugate
** Side effect on the quaternion
*/

void	qtrn_conj(t_qtrn *const q)
{
	q->c.x *= -1;
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
