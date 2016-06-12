/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 18:17:22 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/12 22:51:30 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "settings.h"
#include "geometry.h"

typedef struct s_frac
{
	char	is_locked;
	char	is_bonus;
	char	is_julia;
	t_real	zoom;
	t_real	light;
	t_real	power;
	size_t	max_iter;
	t_cmplx	c;
	t_cmplx	cntr;
	t_vec3t	speed;
}				t_frac;

int				frac_main(int ac, char **av);
unsigned int	frac_color(size_t ite, t_frac *f);
t_cmplx			frac_julia(t_cmplx *z, t_cmplx *c);
t_cmplx			frac_apply(t_cmplx *z, t_cmplx *c, t_real pow, int bonus);
void			frac_reset(t_frac *f);
