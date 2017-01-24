/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easings1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:01:23 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/24 05:54:22 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

int			identity(int const i, int const dout, const int din)
{
	(void)dout;
	(void)din;
	return (i);
}

int			linear_interpolation(int const i, int const dout, int const din)
{
	return ((i * dout) / din);
}

int			ease_inout_sine(int const i, int const dout, int const din)
{
	const t_real	x = (t_real)i;
	const t_real	out = (t_real)dout;
	const t_real	in = (t_real)din;

	return ((int)(out * (1 - cos(x * M_PI / in)) / 2));
}

int			ease_out_sine(int const i, int const dout, int const din)
{
	const t_real	x = (t_real)i;
	const t_real	out = (t_real)dout;
	const t_real	in = (t_real)din;

	return ((int)(out * sin(M_PI_2 * x / in)));
}
