/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 13:36:22 by angagnie          #+#    #+#             */
/*   Updated: 2016/05/31 18:33:45 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

/*
** Matrix :: multiply
** mat_2x3i_times_3x1i	:	M(2,3,Z) x M(3,1,Z)	 ->	M(2,1,Z)
** |							(a, b)			|->	a * b
** No side effect
**
*/

t_mat2x1i	mat_2x3i_times_3x1i(t_mat2x3i *a, t_mat3x1i *b)
{
	return ((t_mat2x1i){{
		a->pnt[0].x * b->c.x + a->pnt[1].x * b->c.y + a->pnt[2].x * b->c.z,
		a->pnt[0].y * b->c.x + a->pnt[1].y * b->c.y + a->pnt[2].y * b->c.z
		}});
}

t_mat3x1	mat_3x3_times_3x1(t_mat3x3 *a, t_mat3x1 *b)
{
	return ((t_mat3x1){{
		a->pnt[0].x * b->c.x + a->pnt[1].x * b->c.y + a->pnt[2].x * b->c.z,
		a->pnt[0].y * b->c.x + a->pnt[1].y * b->c.y + a->pnt[2].y * b->c.z,
		a->pnt[0].z * b->c.x + a->pnt[1].z * b->c.y + a->pnt[2].z * b->c.z
	}});
}

/*
** mat_3x3_times_3x3 :	M(3,R)^2	->		M(3,R)
**						(a, b)		|->		a * b
*/

void		mat_3x3_times_3x3(t_mat3x3 *a, t_mat3x3 *b)
{
	return ((t_mat3x3){{
		a->pnt[0].x * b->pnt[0].x + a->pnt[1].x * b->pnt[0].y
		+ a->pnt[2].x * b->pnt[0].z,
		a->pnt[0].y * b->pnt[0].x + a->pnt[1].y * b->pnt[0].y
		+ a->pnt[2].y * b->pnt[0].z,
		a->pnt[0].z * b->pnt[0].x + a->pnt[1].z * b->pnt[0].y
		+ a->pnt[2].z * b->pnt[0].z}, {
		a->pnt[0].x * b->pnt[1].x + a->pnt[1].x * b->pnt[1].y
		+ a->pnt[2].x * b->pnt[1].z,
		a->pnt[0].y * b->pnt[1].x + a->pnt[1].y * b->pnt[1].y
		+ a->pnt[2].y * b->pnt[1].z,
		a->pnt[0].z * b->pnt[1].x + a->pnt[1].z * b->pnt[1].y
		+ a->pnt[2].z * b->pnt[1].z}, {
		a->pnt[0].x * b->pnt[2].x + a->pnt[1].x * b->pnt[2].y
		+ a->pnt[2].x * b->pnt[2].z,
		a->pnt[0].y * b->pnt[2].x + a->pnt[1].y * b->pnt[2].y
		+ a->pnt[2].y * b->pnt[2].z,
		a->pnt[0].z * b->pnt[2].x + a->pnt[1].z * b->pnt[2].y
		+ a->pnt[2].z * b->pnt[2].z
		}});
}
