/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_misc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 19:26:09 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/10 15:57:36 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"
#include "ggl.h"

t_mat3x3	mat_get_transformation(t_gnode *n)
{
	t_mat3x3	ans;
	t_mat3x3	tmp;

	ans = mat_scale(n->scale);
	tmp = mat_xaxis(n->alpha);
	ans = mat_3x3_times_3x3(&ans, &tmp);
	tmp = mat_yaxis(n->beta);
	ans = mat_3x3_times_3x3(&ans, &tmp);
	tmp = mat_zaxis(n->gamma);
	ans = mat_3x3_times_3x3(&ans, &tmp);
	return (ans);
}

t_mat4x4	mat4_get_transformation(t_gnode *n)
{
	t_mat4x4	ans;
	t_mat4x4	tmp;

	ans = mat4_scale(n->scale);
	tmp = mat4_xaxis(n->alpha);
	ans = mat_4x4_times_4x4(&ans, &tmp);
	tmp = mat4_yaxis(n->beta);
	ans = mat_4x4_times_4x4(&ans, &tmp);
	tmp = mat4_zaxis(n->gamma);
	ans = mat_4x4_times_4x4(&ans, &tmp);
	ans.pnt[3].x = X(n->pos);
	ans.pnt[3].y = Y(n->pos);
	ans.pnt[3].z = Z(n->pos);
	return (ans);
}
