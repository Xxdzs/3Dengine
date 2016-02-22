/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 12:32:44 by angagnie          #+#    #+#             */
/*   Updated: 2016/02/22 15:10:29 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Because I chose vectors to be columns,
** matrices are column-major,
** hence the transposed source code
*/

t_mat4x4	qtrn_to_mat(t_qtrn q)
{
	return ((t_mat4x4) {
		q.c.x, -q.c.y, -q.c.z, -q.c.w,
		q.c.y, q.c.x, q.c.w, -q.c.z,
		q.c.z, -q.c.w, q.c.x, q.c.y,
		q.c.w, q.c.z, -q.c.y, q.c.x
	});
}

t_qtrn	mat_to_qtrn(t_mat4x4 m)
{
	return ((t_qtrn){m->pnt[0].x, m->pnt[1].x, m->pnt[2].x, m->pnt[3].x});
}

