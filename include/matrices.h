/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 10:24:36 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/13 01:48:26 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

# include "geometry.h"
# include "settings.h"

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
	t_real	raw[9];
}				t_mat3x3;

typedef union	u_mat4x4
{
	t_pnt4	pnt[4];
	t_vec4	vec[4];
	t_real	raw[16];
}				t_mat4x4;

typedef union	u_mat2x3i
{
	t_pnt2i	pnt[3];
	t_vec2i vec[3];
	int		raw[6];
}				t_mat2x3i;

typedef t_vec2i	t_mat2x1i;
typedef t_vec2	t_mat2x1;
typedef t_vec3i	t_mat3x1i;
typedef t_vec3	t_mat3x1;
typedef t_vec4	t_mat4x1;

t_mat2x1i		mat_2x3i_times_3x1i(const t_mat2x3i *a, const t_mat3x1i *b);
t_mat3x1		mat_3x3_times_3x1(const t_mat3x3 *a, const t_mat3x1 *b);
t_mat4x1		mat_4x4_times_4x1(const t_mat4x4 *a, const t_mat4x1 *b);
t_mat3x3		mat_3x3_times_3x3(const t_mat3x3 *a, const t_mat3x3 *b);
t_mat4x4		mat_4x4_times_4x4(const t_mat4x4 *a, const t_mat4x4 *b);
t_mat3x3		mat_xaxis(t_real a);
t_mat3x3		mat_yaxis(t_real a);
t_mat3x3		mat_zaxis(t_real a);
t_mat3x3		mat_scale(t_real a);
t_mat4x4		mat4_xaxis(t_real a);
t_mat4x4		mat4_yaxis(t_real a);
t_mat4x4		mat4_zaxis(t_real a);
t_mat4x4		mat4_scale(t_real a);
void			mat3x3_print(const t_mat3x3 *const m);

#endif
