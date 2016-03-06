/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 13:07:57 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/06 13:42:49 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H

# include "settings.h"

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
	t_real	x;
	t_real	y;
}				t_pnt2;

typedef union	u_vec2
{
	t_pnt2	c;
	t_real	m[2];
	struct
	{
		t_real	rep;
		t_real	imp;
	}		r;
	struct
	{
		t_real	mod;
		t_real	arg;
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
	t_real	x;
	t_real	y;
	t_real	z;
}				t_pnt3;

typedef union	u_vec3
{
	t_pnt3	c;
	t_real	m[3];
	struct
	{
		t_real	phi;
		t_real	theta;
		t_real	rho;
	}		s;
	struct
	{
		t_real	r;
		t_real	theta;
		t_real	z;
	}		cyl;
}				t_vec3;

/*
** -----===== 4 Dimensions =====-----
*/

typedef struct	s_pnt4
{
	t_real	x;
	t_real	y;
	t_real	z;
	t_real	w;
}				t_pnt4;

/*
** H is isomorphic to M(4,1,R), hence	m
** -(Matrix)
** H is isomorphic to R^4, hence		c
** -(Carthesian Coordinates)
** One can decompose a quaternion into
** |	a vector part (in R^3)		v
** |	a scalar part (in R)		s
** | hence								d
** -(Decomposition)
*/

typedef union	u_qtrn
{
	t_real	m[4];
	t_pnt4	c;
	struct
	{
		t_vec3	v;
		t_real	s;
	}		d;
}				t_qtrn;

void	carth2polar(t_vec2 *v);
void	polar2carth(t_vec2 *v);
void	carth2cylin(t_vec3 *v);
void	cylin2carth(t_vec3 *v);
void	carth2spher(t_vec3 *v);
void	spher2carth(t_vec3 *v);

#endif
