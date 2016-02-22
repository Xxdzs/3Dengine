/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 13:07:57 by angagnie          #+#    #+#             */
/*   Updated: 2016/02/22 15:59:20 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H

/*
** -----===== 2 Dimensions =====-----
*/

typedef struct	s_pnt2i
{
	int		x;
	int		y;
}				t_pnt2i;

typedef union	s_vec2i
{
	t_pnt2i	c;
	int		m[2];
	struct
	{
		int	width;
		int	height;
	}		d;
}				t_vec2i;

typedef struct	s_pnt2
{
	float	x;
	float	y;
}				t_pnt2;

typedef union	s_vec2
{
	t_pnt2	c;
	float	m[2];
}				t_vec2;

typedef struct	s_cmplx
{
	float	rep;
	float	imp;
	float	arg;
	float	mod;
}				t_cmplx;

/*
** -----===== 3 Dimensions =====-----
*/

typedef struct	s_pnt3i
{
	int		x;
	int		y;
	int		z;
}				t_pnt3i;

typedef union	s_vec3i
{
	t_pnt3i	c;
	int		m[3];
	struct
	{
		int width;
		int	height;
		int	depth;
	}		d;
}				t_vec3i;

typedef struct	s_pnt3
{
	float	x;
	float	y;
	float	z;
}				t_pnt3;

typedef union	s_vec3
{
	t_pnt3	c;
	float	m[3];
}				t_vec3;

/*
** -----===== 4 Dimensions =====-----
*/

typedef struct	s_pnt4
{
	float	x;
	float	y;
	float	z;
	float	w;
}				t_pnt4;

typedef union	s_qtrn
{
	t_pnt4	c;
	struct
	{
		t_pnt3	v;
		float	s;
	}		d;
	float	m[4];
}				t_qtrn;

#endif
