/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_mult.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 13:36:22 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/05 19:49:39 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

/*
** Matrix :: multiply
** mat_2x3i_times_3x1i	:	M(2,3,Z) x M(3,1,Z)	 ->	M(2,1,Z)
** |							(a, b)			|->	a * b
** No side effect
*/

t_mat2x1i		mat_2x3i_times_3x1i(const t_mat2x3i *a, const t_mat3x1i *b)
{
	return ((t_mat2x1i){{
		a->pnt[0].x * b->c.x + a->pnt[1].x * b->c.y + a->pnt[2].x * b->c.z,
		a->pnt[0].y * b->c.x + a->pnt[1].y * b->c.y + a->pnt[2].y * b->c.z
		}});
}

t_mat3x1		mat_3x3_times_3x1(const t_mat3x3 *a, const t_mat3x1 *b)
{
	return ((t_mat3x1){{
		a->pnt[0].x * b->c.x + a->pnt[1].x * b->c.y + a->pnt[2].x * b->c.z,
		a->pnt[0].y * b->c.x + a->pnt[1].y * b->c.y + a->pnt[2].y * b->c.z,
		a->pnt[0].z * b->c.x + a->pnt[1].z * b->c.y + a->pnt[2].z * b->c.z
	}});
}

t_mat4x1		mat_4x4_times_4x1(const t_mat4x4 *a, const t_mat4x1 *b)
{
	return ((t_mat4x1){{
		a->pnt[0].x * b->c.x + a->pnt[1].x * b->c.y
			+ a->pnt[2].x * b->c.z + a->pnt[3].x * b->c.w,
		a->pnt[0].y * b->c.x + a->pnt[1].y * b->c.y
			+ a->pnt[2].y * b->c.z + a->pnt[3].y * b->c.w,
		a->pnt[0].z * b->c.x + a->pnt[1].z * b->c.y
			+ a->pnt[2].z * b->c.z + a->pnt[3].z * b->c.w,
		a->pnt[0].w * b->c.x + a->pnt[1].w * b->c.y
			+ a->pnt[2].w * b->c.z + a->pnt[3].w * b->c.w
	}});
}

/*
** mat_3x3_times_3x3 :	M(3,R)^2	->		M(3,R)
** |					(a, b)		|->		a * b
*/

t_mat3x3		mat_3x3_times_3x3(const t_mat3x3 *a, const t_mat3x3 *b)
{
	return ((t_mat3x3){{
			(t_pnt3){
		a->pnt[0].x * b->pnt[0].x + a->pnt[1].x * b->pnt[0].y
		+ a->pnt[2].x * b->pnt[0].z,
		a->pnt[0].y * b->pnt[0].x + a->pnt[1].y * b->pnt[0].y
		+ a->pnt[2].y * b->pnt[0].z,
		a->pnt[0].z * b->pnt[0].x + a->pnt[1].z * b->pnt[0].y
		+ a->pnt[2].z * b->pnt[0].z
			}, (t_pnt3){
		a->pnt[0].x * b->pnt[1].x + a->pnt[1].x * b->pnt[1].y
		+ a->pnt[2].x * b->pnt[1].z,
		a->pnt[0].y * b->pnt[1].x + a->pnt[1].y * b->pnt[1].y
		+ a->pnt[2].y * b->pnt[1].z,
		a->pnt[0].z * b->pnt[1].x + a->pnt[1].z * b->pnt[1].y
		+ a->pnt[2].z * b->pnt[1].z
			}, (t_pnt3){
		a->pnt[0].x * b->pnt[2].x + a->pnt[1].x * b->pnt[2].y
		+ a->pnt[2].x * b->pnt[2].z,
		a->pnt[0].y * b->pnt[2].x + a->pnt[1].y * b->pnt[2].y
		+ a->pnt[2].y * b->pnt[2].z,
		a->pnt[0].z * b->pnt[2].x + a->pnt[1].z * b->pnt[2].y
		+ a->pnt[2].z * b->pnt[2].z
			}
		}});
}

/*
** mat_4x4_times_4x4 :	M(4,R)^2	->		M(4,R)
** |					(a, b)		|->		a * b
*/

t_mat4x4		mat_4x4_times_4x4(const t_mat4x4 *a, const t_mat4x4 *b)
{
	t_mat4x4	ans;
	t_pnt3i		i;

	ans = *a;
	i.x = 4;
	while (i.x-- > 0 && (i.y = 4))
		while (i.y-- > 0 && (i.z = 4))
		{
			ans.vec[i.x].m[i.y] = 0;
			while (i.z-- > 0)
				ans.vec[i.x].m[i.y] += a->vec[i.z].m[i.y] * b->vec[i.x].m[i.z];
		}
	return (ans);
}
