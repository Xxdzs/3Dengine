/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:04:21 by angagnie          #+#    #+#             */
/*   Updated: 2016/05/31 17:01:44 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "ggl.h"

/*
** Quaternion :: Get the rotation
** f :	H x H	-> H
**		(q, p)	|-> q * p * inv(q)
*/

t_qtrn	qtrn_get_rotated(const t_qtrn *const a, const t_qtrn *const b)
{
	t_qtrn	ans;
	t_qtrn	tmp;

	ans = qtrn_prod(b, a);
	tmp = qtrn_get_inv(b);
	printf("inv(b) = (%f, %f, %f, %f)\n",
		   b->v.m[0], b->v.m[1], b->v.m[2], b->v.m[3]); // < --
	qtrn_mult(&ans, &tmp);
	return (ans);
}

/*
** Quaternion :: Apply the rotation
** f :	H x H	-> H
**		(q, p)	|-> q * p * inv(q)
** Side effect on the first quaternion
*/

void	qtrn_rotate(t_qtrn *const a, const t_qtrn *const b)
{
	*a = qtrn_get_rotated(a, b);
}
