/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 13:07:57 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/23 23:55:17 by angagnie         ###   ########.fr       */
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
		unsigned	width;
		unsigned	height;
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
		unsigned	width;
		unsigned	height;
		unsigned	depth;
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

typedef union	u_vec4
{
	t_pnt4	c;
	t_real	m[4];
	struct
	{
		t_vec3	v;
		t_real	s;
	}		d;
}				t_vec4;

typedef struct	s_vec4t
{
	t_type	type;
	t_vec4	v;
}				t_vec4t;

typedef t_vec4t	t_qtrn;

# define X(A) (A.v.c.x)
# define Y(A) (A.v.c.y)
# define Z(A) (A.v.c.z)
# define W(A) (A.v.c.z)

# define XP(A) (A->v.c.x)
# define YP(A) (A->v.c.y)
# define ZP(A) (A->v.c.z)
# define WP(A) (A->v.c.z)

# define WIDTH(A) (A->v.d.width)
# define HEIGHT(A) (A->v.d.height)
# define DEPTH(A) (A->v.d.depth)

# define REP(A) (A.v.r.rep)
# define IMP(A) (A.v.r.imp)
# define MOD(A) (A.v.p.mod)
# define ARG(A) (A.v.p.arg)

# define REPP(A) (A->v.r.rep)
# define IMPP(A) (A->v.r.imp)
# define MODP(A) (A->v.p.mod)
# define ARGP(A) (A->v.p.arg)

# define RHO(A) (A.v.s.rho)
# define THETA(A) (A.v.s.theta)
# define PHI(A) (A.v.s.phi)
# define R(A) (A.v.cyl.r)

# define RHOP(A) (A->v.s.rho)
# define THETAP(A) (A->v.s.theta)
# define PHIP(A) (A->v.s.phi)
# define RP(A) (A->v.cyl.r)

# define SCALAR(Q) (Q.v.d.s)
# define VECTOR(Q) (Q.v.d.v)
# define QRHO(Q) (Q.v.d.v.s.rho)
# define QTHETA(Q) (Q.v.d.v.s.theta)
# define QPHI(Q) (Q.v.d.v.s.phi)
# define QR(Q) (Q.v.d.v.cyl.r)

# define SCALARP(Q) (Q->v.d.s)
# define VECTORP(Q) (Q->v.d.v)
# define QRHOP(Q) (Q->v.d.v.s.rho)
# define QTHETAP(Q) (Q->v.d.v.s.theta)
# define QPHIP(Q) (Q->v.d.v.s.phi)
# define QRP(Q) (Q->v.d.v.cyl.r)

/*
** -----=====  Constructors  =====-----
*/

# define NEW_VEC2(X, Y) ((t_vec2t){CARTHESIAN, {{X, Y}}})
# define NEW_VEC3(X, Y, Z) ((t_vec3t){CARTHESIAN, {{X, Y, Z}}})
# define NEW_VEC4(...) ((t_vec4t){CARTHESIAN, {{__VA_ARGS__}}})

# define NEW_CMPLX(A, B) NEW_VEC2(A, B)
# define NEW_QTRN(...) NEW_VEC4(__VA_ARGS__)

t_qtrn			qtrn_cpy(const t_qtrn *const q, const t_type t);
t_cmplx			cmplx_cpy(const t_cmplx *const z, const t_type t);
t_vec3t			*vec3_alloc(const t_real a, const t_real b, const t_real c);

/*
** -----=====  Member Functions  =====-----
*/

t_cmplx			cmplx_log(const t_cmplx *c);
t_cmplx			cmplx_exp(const t_cmplx *c);
t_cmplx			cmplx_cos(const t_cmplx *c);
t_cmplx			cmplx_sin(const t_cmplx *c);
t_cmplx			cmplx_sinh(const t_cmplx *c);

t_cmplx			cmplx_pow(const t_cmplx *c, const t_real n);
t_real			cmplx_mod(const t_cmplx *c);
t_real			cmplx_rep(const t_cmplx *c);
t_cmplx			cmplx_square(const t_cmplx *z);

t_qtrn			qtrn_external_prod(const t_qtrn *const a, const t_real s);
void			qtrn_external_mult(t_qtrn *const a, const t_real s);
t_qtrn			qtrn_sum(const t_qtrn *a, const t_qtrn *b);
void			qtrn_add(t_qtrn *const a, const t_qtrn *const b);
t_qtrn			qtrn_prod(const t_qtrn *const a, const t_qtrn *const b);
void			qtrn_mult(t_qtrn *const a, const t_qtrn *const b);
t_qtrn			qtrn_get_inv(const t_qtrn *const q);
void			qtrn_inv(t_qtrn *const q);
t_qtrn			qtrn_get_conj(const t_qtrn *const q);
void			qtrn_conj(t_qtrn *const q);
t_qtrn			qtrn_get_rotated(const t_qtrn *const a, const t_qtrn *const b);
void			qtrn_rotate(t_qtrn *const a, const t_qtrn *const b);
t_real			qtrn_get_norm(const t_qtrn *const q);
t_real			qtrn_get_modulus(const t_qtrn *const q);
char			*qtrn_to_string(const t_qtrn *const q);

/*
** ---== Conversion ==---
*/

void			carth2polar(t_cmplx *v);
void			polar2carth(t_cmplx *v);
void			carth2cylin(t_vec3t *v);
void			cylin2carth(t_vec3t *v);
void			carth2spher(t_vec3t *v);
void			spher2carth(t_vec3t *v);
void			spher2cylin(t_vec3t *v);
void			cylin2spher(t_vec3t *v);
t_real			perso2rqtrn(t_qtrn *q);

#endif
