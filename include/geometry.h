/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 13:07:57 by angagnie          #+#    #+#             */
/*   Updated: 2016/02/24 16:37:46 by sid              ###   ########.fr       */
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

typedef union	u_vec2i
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

typedef union	u_vec2
{
	t_pnt2	c;
	float	m[2];
	struct
	{
		float	mod;
		float	arg;
	}		p;
}				t_vec2;

/*
** -----===== 3 Dimensions =====-----
*/

typedef struct	s_pnt3i
{
	int		x;
	int		y;
	int		z;
}				t_pnt3i;

typedef union	u_vec3i
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

typedef union	u_vec3
{
	t_pnt3	c;
	float	m[3];
	struct
	{
		float	phi;
		float	theta;
		float	rho;
	}		s;
	struct
	{
		float	r;
		float	theta;
		float	z;
	}		cyl;
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

/*
** H is isomorphic to M(4,1,R), hence	m
** -(Matrix)
** H is isomorphic to R^4, hence		c
** -(Carthesian Coordinates)
** One can decompose a quaternion into
** |	a vector part (in R^3)		v
** |	a scalar part (in R)		s
** |hence								d
** -(Decomposition)
*/

typedef union	u_qtrn
{
	float	m[4];
	t_pnt4	c;
	struct
	{
		t_vec3	v;
		float	s;
	}		d;
}				t_qtrn;

#endif
