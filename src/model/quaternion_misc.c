/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:04:21 by angagnie          #+#    #+#             */
/*   Updated: 2016/05/31 14:23:51 by angagnie         ###   ########.fr       */
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
	if (q->type == CARTHESIAN)
		ft_dyna_append(&acc, "carth ", 6);
	else if (q->type == CYLINDRICAL)
		ft_dyna_append(&acc, "cylin ", 6);
	else
		ft_dyna_append(&acc, "spher ", 6);
	while (i < 4)
	{
		tmp = ft_itoa((int)(q->v.m[i]));
		ft_dyna_append(&acc, tmp, ft_strlen(tmp));
		free(tmp);
		ft_dyna_append(&acc, ".", 1);
		tmp = ft_itoa((int)((q->v.m[i] - trunc(q->v.m[i])) * 10000));
		ft_dyna_append(&acc, tmp, ft_strlen(tmp));
		free(tmp);
		if (i++ < 3)
			ft_dyna_append(&acc, ", ", 2);
	}
	ft_dyna_append(&acc, ")\0", 2);
	return ((char *)acc.data);
}
