/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:04:21 by angagnie          #+#    #+#             */
/*   Updated: 2016/02/25 19:16:29 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Quaternion :: Constructors
*/

t_qtrn	qtrn_new_carth(float a, float b, float c, float d)
{
	return ((t_qtrn){{a, b, c, d}});
}

/*
t_qtrn	qtrn_new_cylin()
{
	return ();
}
*/

/*
** Quaternion :: Get the sum
*/

t_qtrn	qtrn_sum(t_qtrn *a, t_qtrn *b)
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

void	qtrn_add(t_qtrn *a, t_qtrn *b)
{
	int i;

	i = 4;
	while (i-- > 0)
		a->m[i] += b->m[i];
}

/*
** Quaternion :: Get the product
*/

t_qtrn	qtrn_prod(t_qtrn *q, t_qtrn *h)
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

void	qtrn_mult(t_qtrn *q, t_qtrn *h)
{
	float qx;
	float qy;
	float qz;

	qx = q->c.w * h->c.x + q->c.x * h->c.w + q->c.y * h->c.z - q->c.z * h->c.y;
	qy = q->c.w * h->c.y + q->c.y * h->c.w - q->c.x * h->c.z + q->c.z * h->c.x;
	qz = q->c.w * h->c.z + q->c.z * h->c.w + q->c.x * h->c.y - q->c.y * h->c.x;
	q->c.w = q->c.w * h->c.w - q->c.x * h->c.x - q->c.y * h->c.y - q->c.z * h->c.z;
	q->c.x = qx;
	q->c.y = qy;
	q->c.z = qz;
}

/*
** Quaternion :: Get the inverse
*/

t_qtrn	qtrn_get_inv(t_qtrn *q)
{
	float const tmp = q->c.w * q->c.w
		+ q->c.x * q->c.x
		+ q->c.y * q->c.y
		+ q->c.z * q->c.z;

	return ((t_qtrn){{-q->c.x / tmp, -q->c.y / tmp, -q->c.z / tmp, q->c.w / tmp}});
}

/*
** Quaternion :: Invert
** Side effect on the quaternion
*/

void	qtrn_inv(t_qtrn *q)
{
	float const tmp = q->c.w * q->c.w
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

t_qtrn	qtrn_get_conj(t_qtrn *q)
{
	return ((t_qtrn){{-q->c.x, -q->c.y, -q->c.z, q->c.w}});
}

/*
** Quaternion :: Conjugate
** Side effect on the quaternion
*/

void	qtrn_conj(t_qtrn *q)
{
	q->c.x *= -1;
	q->c.y *= -1;
	q->c.z *= -1;
}

