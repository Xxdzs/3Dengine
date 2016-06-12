/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 18:17:22 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/12 18:39:48 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "settings.h"
#include "geometry.h"

typedef t_cmplx (*t_fun)();

typedef struct s_frac
{
	int		is_julia;
	int		lock;
	t_cmplx	c;
	t_fun	f;
	t_cmplx	cntr;
	t_real	zoom;
	size_t	max_iter;
	t_real	light;
	t_vec3t	speed;
}				t_frac;

int				frac_main(int ac, char **av);
unsigned int	frac_color(size_t ite, t_frac *f);
t_cmplx			cmplx_julia(t_cmplx *z, t_cmplx *c);
t_cmplx			cmplx_log2(t_cmplx *z, t_cmplx *c);
