/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:04:21 by angagnie          #+#    #+#             */
/*   Updated: 2016/05/17 17:50:50 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
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
		QTHETA(ans) = QTHETA(a);
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
		QWP(a) *= s;
	}
	else
	{
		QRHOP(a) *= s;
		WP(a) *= s;
	}
}


/*
** Quaternion :: Get the sum
*/

t_qtrn	qtrn_sum(const t_qtrn *a, const t_qtrn *b)
{
	t_qtrn ans;
	t_qtrn tmp;

	ans = *a;
	tmp = *b;
	if (ans.type == CYLINDRICAL)
		cylin2carth(&ans);
	else if (ans.type == SPERICAL)
		spher2carth(&ans);
	if (tmp.type == CYLINDRICAL)
		cylin2carth(&tmp);
	else if (tmp.type == SPERICAL)
		spher2carth(&tmp);
	X(ans) += X(tmp);
	Y(ans) += Y(tmp);
	Z(ans) += Z(tmp);
	W(ans) += W(tmp);
	return (ans);
}

/*
** Quaternion :: Add
** Side effect on the first quaternion
*/

void	qtrn_add(t_qtrn *const a, const t_qtrn *const b)
{
	int		i;
	t_type	;

	if (a->type == CYLINDRICAL)
		cylin2carth(a);
	else if (a->type == SPERICAL)
		spher2carth(a);
	if (b->type == CYLINDRICAL)
		cylin2carth(b);
	else if (a->type == SPERICAL)
		spher2carth(b);
	i = 4;
	while (i-- > 0)
		a->v.m[i] += b->v.m[i];
}

/*
** Quaternion :: Get the product
*/

t_qtrn	qtrn_prod(const t_qtrn *const q, const t_qtrn *const h)
{
	return (NEW_QTRN(
		WP(q) * XP(h) + XP(q) * WP(h) + YP(q) * ZP(h) - ZP(q) * YP(h),
		WP(q) * YP(h) + YP(q) * WP(h) - XP(q) * ZP(h) + ZP(q) * XP(h),
		WP(q) * ZP(h) + ZP(q) * WP(h) + XP(q) * YP(h) - YP(q) * XP(h),
		WP(q) * WP(h) - XP(q) * XP(h) - YP(q) * YP(h) - ZP(q) * ZP(h)
		));
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
	return (NEW_QTRN(-XP(q) / tmp, -YP(q) / tmp,
		-ZP(q) / tmp, WP(q) / tmp));
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
	return (NEW_QTRN(-XP(q), -YP(q), -ZP(q), WP(q)));
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
** Quaternion :: Get the rotation
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

/*
** Quaternion :: Apply the rotation
** f :	H x H	-> H
**		(q, p)	|-> q * p * inv(q)
*/

void	qtrn_rotate(t_qtrn *const to_rotate, t_qtrn rotator)
{
	t_qtrn	ans;

	ans = qtrn_get_inv(&rotator);
	qtrn_mult(to_rotate, &ans);
	qtrn_mult(&rotator, to_rotate);
	ft_memcpy(to_rotate, &rotator, sizeof(ans));
}

/*
** Quaternion :: To string
*/

char	*qtrn_to_string(const t_qtrn *const q)
{
	t_dyna	acc;
	char	*tmp;
	int		i;

	acc = ft_dyna_new(sizeof(char));
	ft_dyna_datainit(&acc);
	i = 0;
	ft_dyna_append(&acc, "(", 1);
	while (i < 4)
	{
		tmp = ft_itoa(q->v.m[i]);
		ft_dyna_append(&acc, tmp, ft_strlen(tmp));
		free(tmp);
		if (i++ < 3)
			ft_dyna_append(&acc, ", ", 2);
	}
	ft_dyna_append(&acc, ")\0", 2);
	return ((char *)acc.data);
}
