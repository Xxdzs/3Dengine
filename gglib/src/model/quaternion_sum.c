/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:04:21 by angagnie          #+#    #+#             */
/*   Updated: 2016/05/31 14:19:19 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "ggl.h"

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
