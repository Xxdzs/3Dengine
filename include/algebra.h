/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 13:13:56 by angagnie          #+#    #+#             */
/*   Updated: 2016/02/16 14:58:21 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGEBRA_H
# define ALGEBRA_H

typedef union	u_mat2x2i
{
	t_pnt2i	pnt[2];
	t_vec2i	vec[2];
	int		raw[4];
}				t_mat2x2i;

typedef union	u_mat3x3i
{
	t_pnt3i	pnt[3];
	t_vec3i	vec[3];
	int		raw[9];
}				t_mat3x3i;

typedef union	u_mat3x3
{
	t_pnt3	pnt[3];
	t_vec3	vec[3];
	float	raw[9];
}				t_mat3x3;

typedef union	u_mat4x4
{
	t_pnt4	pnt[4];
	t_qtrn	vec[4];
	float	raw[16];
}				t_mat4x4;

typedef union	u_mat2x3i
{
	t_pnt2i	pnt[3];
	t_vec2i vec[3];
	int		raw[6];
}				t_mat2x3i;

#endif
