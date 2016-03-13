/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 13:36:22 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/13 14:17:34 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

/*
** Matrix :: multiply
** mult	:	M(2,3,Z) x M(3,1,Z)	 ->	M(2,1,Z)
** |			(a, b)			|->	a * b
** No side effect
*/

t_mat2x1i	mat_proj3v2(t_mat2x3i *a, t_mat3x1i *b)
{
	return ((t_mat2x1i){{
		a->pnt[0].x * b->c.x + a->pnt[1].x * b->c.y + a->pnt[2].x * b->c.z,
		a->pnt[0].y * b->c.x + a->pnt[1].y * b->c.y + a->pnt[2].y * b->c.z
		}});
}

t_mat3x1	mat_3x3_times_3x1(t_mat3x3 *a, t_mat3x1 *b)
{
	(void)a;
	return (*b);
}
