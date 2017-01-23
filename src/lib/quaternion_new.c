/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:04:21 by angagnie          #+#    #+#             */
/*   Updated: 2016/05/31 14:40:42 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "ggl.h"

/*
** Quaternion :: Constructors
*/

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
