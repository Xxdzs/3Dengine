/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:04:21 by angagnie          #+#    #+#             */
/*   Updated: 2016/05/18 12:43:09 by angagnie         ###   ########.fr       */
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

t_qtrn	qtrn_cpy(const t_qtrn *const q, const t_type t)
{
	t_qtrn	ans;

	ans = *q;
	if (t == CARTHESIAN)
	{
		if (q->type == SPHERICAL)
			spher2carth((t_vec3t *)&ans);
		else if (q->type == CYLINDRICAL)
			cylin2carth((t_vec3t *)&ans);
	}
	else if (t == CYLINDRICAL)
	{
		if (q->type == CARTHESIAN)
			carth2cylin((t_vec3t *)&ans);
		else if (q->type == SPHERICAL)
			spher2cylin((t_vec3t *)&ans);
	}
	else
	{
		if (q->type == CARTHESIAN)
			carth2spher((t_vec3t *)&ans);
		else if (q->type == CYLINDRICAL)
			cylin2spher((t_vec3t *)&ans);
	}
	return (ans);
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
** Quaternion :: Get the sum
*/

t_qtrn	qtrn_sum(const t_qtrn *a, const t_qtrn *b)
{
	t_qtrn ans;
	t_qtrn tmp;

	ans = qtrn_cpy(a, CARTHESIAN);
	tmp = qtrn_cpy(b, CARTHESIAN);
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
	int				i;
	const t_type	save = a->type;
	t_qtrn			tmp;
	t_qtrn			ans;

	ans = qtrn_cpy(a, CARTHESIAN);
	tmp = qtrn_cpy(b, CARTHESIAN);
	i = 4;
	while (i-- > 0)
		ans.v.m[i] += tmp.v.m[i];
	*a = qtrn_cpy(&ans, save);
}

/*
** Quaternion :: Get the product
*/

t_qtrn	qtrn_prod(const t_qtrn *const a, const t_qtrn *const b)
{
	const t_qtrn		q = qtrn_cpy(a, CARTHESIAN);
	const t_qtrn		h = qtrn_cpy(b, CARTHESIAN);

    return (NEW_QTRN(
		W(q) * X(h) + X(q) * W(h) + Y(q) * Z(h) - Z(q) * Y(h),
		W(q) * Y(h) + Y(q) * W(h) - X(q) * Z(h) + Z(q) * X(h),
		W(q) * Z(h) + Z(q) * W(h) + X(q) * Y(h) - Y(q) * X(h),
		W(q) * W(h) - X(q) * X(h) - Y(q) * Y(h) - Z(q) * Z(h)
	));
}

/*
** Quaternion :: Multiply
** Side effect on the first quaternion
*/

void	qtrn_mult(t_qtrn *const a, const t_qtrn *const b)
{
	const t_qtrn		q = qtrn_cpy(a, CARTHESIAN);
	const t_qtrn		h = qtrn_cpy(b, CARTHESIAN);
	t_qtrn		ans;

	ans = NEW_QTRN(
		W(q) * X(h) + X(q) * W(h) + Y(q) * Z(h) - Z(q) * Y(h),
		W(q) * Y(h) + Y(q) * W(h) - X(q) * Z(h) + Z(q) * X(h),
		W(q) * Z(h) + Z(q) * W(h) + X(q) * Y(h) - Y(q) * X(h),
		W(q) * W(h) - X(q) * X(h) + Y(q) * Y(h) + Z(q) * Z(h)
	);
	*a = qtrn_cpy(&ans, a->type);
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
	if (q->type == CARTHESIAN)
		return (NEW_QTRN(-XP(q), -YP(q), -ZP(q), WP(q)));
	else if (q->type == CYLINDRICAL)
		return ((t_qtrn){CYLINDRICAL, {{
			QRP(q), QTHETAP(q) + M_PI, -ZP(q), WP(q)}}});
	return ((t_qtrn){SPHERICAL, {{
		QRHOP(q), THETAP(q) + M_PI, QPHIP(q) + M_PI, WP(q)}}});
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
