/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:04:21 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/03 09:59:51 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "ggl.h"

t_real	qtrn_get_norm(const t_qtrn *const q)
{
	if (q->type == CARTHESIAN)
		return (XP(q) * XP(q) + YP(q) * YP(q)
			+ ZP(q) * ZP(q) + WP(q) * WP(q));
	else if (q->type == CYLINDRICAL)
		return (ZP(q) * ZP(q) + QRP(q) * QRP(q));
	else
		return (QRHOP(q));
}

t_real	qtrn_get_modulus(const t_qtrn *const q)
{
	return (sqrt(qtrn_get_norm(q)));
}
