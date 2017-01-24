/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 18:17:22 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/24 07:47:28 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H

# include "ggl.h"

/*
** Collections of functions linked to fractals
** t_frac -extends-> t_env
*/

typedef struct	s_frac
{
	t_env	super;
	char	is_locked;
	char	is_bonus;
	char	is_julia;
	char	function;
	t_real	zoom;
	t_real	light;
	t_real	power;
	size_t	max_iter;
	t_cmplx	c;
	t_cmplx	cntr;
	t_vec3t	speed;
}				t_frac;

/*
** The main for fractol
*/

int				frac_main(int ac, char **av);

/*
** The three functions to handle user's input
*/

int				frac_key_hook(int keycode, void *param);
int				frac_mouse_click(int button, int x, int y, void *param);
int				frac_mouse_move(int x, int y, void *param);

unsigned int	frac_color(size_t ite, t_frac *f);
t_cmplx			frac_julia(t_cmplx *z, t_cmplx *c);
t_cmplx			frac_apply(t_cmplx *z, t_cmplx *c, t_real pow, int bonus);
void			frac_reset(t_frac *f);

t_cmplx			frac_transform(t_frac *w, t_pnt2i p, t_pnt2i d);
void			frac_zoom(t_frac *w, t_pnt2i p, t_real zoom);
unsigned		frac_render(t_frac *w, t_pnt2i p, t_pnt2i d);

#endif
