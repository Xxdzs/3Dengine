/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_axis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 10:50:40 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/05 13:18:12 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "matrices.h"
#include "ggl.h"

/*
** mat_xaxis :	R	 ->	M(3,R)
** |					{	1		0		0
** |			a	|->	{	0	 cos(a) -sin(a)
** |					{	0	 sin(a)  cos(a)
*/

t_mat3x3	mat_xaxis(t_real a)
{
	return ((t_mat3x3){{
			{1, 0, 0},
			{0, cos(a), sin(a)},
			{0, -sin(a), cos(a)}
		}});
}

/*
** mat_yaxis :	R	 ->	M(3,R)
** |					{ cos(a)	0	 -sin(a)
** |			a	|->	{	0		1		0
** |					{ sin(a)	0	  cos(a)
*/

t_mat3x3	mat_yaxis(t_real a)
{
	return ((t_mat3x3){{
			{cos(a), 0, sin(a)},
			{0, 1, 0},
			{-sin(a), 0, cos(a)}
		}});
}

/*
** mat_zaxis :	R	 ->	M(3,R)
** |					{ cos(a) -sin(a)	0
** |			a	|->	{ sin(a)  cos(a)	0
** |					{	0		0		1
*/

t_mat3x3	mat_zaxis(t_real a)
{
	return ((t_mat3x3){{
			{cos(a), sin(a), 0},
			{-sin(a), cos(a), 0},
			{0, 0, 1}
		}});
}

/*
** mat_scale :	R	 ->	M(3,R)
** |					{	a		0		0
** |			a	|->	{	0		a		0
** |					{	0		0		a
*/

t_mat3x3	mat_scale(t_real a)
{
	return ((t_mat3x3){{
			{a, 0, 0},
			{0, a, 0},
			{0, 0, a}
		}});
}
