/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 18:17:22 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/12 13:45:20 by angagnie         ###   ########.fr       */
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
}				t_frac;

int				frac_main(int ac, char **av);
