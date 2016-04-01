/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 13:07:57 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/31 11:22:08 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H

# include "settings.h"

typedef enum	e_type
{
	CARTHESIAN,
	CYLINDRICAL,
	SPHERICAL,
	POLAR = CYLINDRICAL,
	RECTANGULAR = CARTHESIAN,
	CARTH = CARTHESIAN,
	CYLIN = CYLINDRICAL,
	SPHER = SPHERICAL
}				t_type;

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

typedef struct	s_vec2t
{
	t_type	type;
	t_vec2	v;
}				t_vec2t;

typedef t_vec2t	t_cmplx;

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
		t_real	rho;
		t_real	theta;
		t_real	phi;
	}		s;
	struct
	{
		t_real	r;
		t_real	theta;
		t_real	z;
	}		cyl;
}				t_vec3;

typedef struct	s_vec3t
{
	t_type	type;
	t_vec3	v;
}				t_vec3t;

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
** |	a vectorial part (in R^3)	v
** |	a scalar part (in R)		s
** | hence								d
** -(Decomposition)
*/

typedef union	u_qtrn
{
	t_pnt4	c;
	t_real	m[4];
	struct
	{
		t_vec3	v;
		t_real	s;
	}		d;
}				t_qtrn;

# define X(A) (A->v.c.x)
# define Y(A) (A->v.c.y)
# define Z(A) (A->v.c.z)

# define REP(A) (A->v.r.rep)
# define IMP(A) (A->v.r.imp)
# define MOD(A) (A->v.p.mod)
# define ARG(A) (A->v.p.arg)

# define RHO(A) (A->v.s.rho)
# define THETA(A) (A->v.s.theta)
# define PHI(A) (A->v.s.phi)
# define R(A) (A->v.cyl.r)

/*
** -----=====  Constructors  =====-----
*/

t_qtrn	qtrn_new(const t_real a, const t_real b, const t_real c, const t_real d);

/*
** -----=====  Destructors  =====-----
*/

/*
** -----=====  Member Functions  =====-----
*/

t_qtrn  qtrn_sum(const t_qtrn *a, const t_qtrn *b);
void    qtrn_add(t_qtrn *const a, const t_qtrn *const b);

void	carth2polar(t_cmplx *v);
void	polar2carth(t_cmplx *v);
void	carth2cylin(t_vec3t *v);
void	cylin2carth(t_vec3t *v);
void	carth2spher(t_vec3t *v);
void	spher2carth(t_vec3t *v);
t_real	perso2rqtrn(t_qtrn *q);

#endif