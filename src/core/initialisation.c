/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:36:43 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/24 07:55:31 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"
#include "easings.h"

void			destroy_env(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img.data);
	mlx_destroy_window(e->mlx, e->win.data);
	if (e->fnct.free)
		e->fnct.free(e);
	db_putstr("\t\t--==  Clear  ==--");
}

void			init_fnct_env(t_env *e)
{
	init_fnct(&e->win, &e->fnct, (void *)e);
	if (e->fnct.loop_hook)
		mlx_loop_hook(e->mlx, e->fnct.loop_hook, (void *)e);
}

void			init_fnct(t_win *w, t_fnct *f, void *e)
{
	mlx_expose_hook(w->data, f->expose, e);
	mlx_hook(w->data, 2, 0, f->key_hook, e);
	mlx_hook(w->data, 6, 4, f->mouse_move, e);
	mlx_mouse_hook(w->data, f->mouse_click, e);
}

void			env_new(t_env *e)
{
	e->mlx = 0;
	e->win = (t_win){NULL, {{0, 0}}, 1};
	e->img = (t_img){NULL, {{0, 0}}, 1, NULL, 0, 0, 0};
	e->fnct = (t_fnct){
		&default_repaint,
		&default_key_hook,
		&default_expose_hook,
		&default_mouse_hook,
		&default_mouse_move_hook,
		NULL, NULL
	};
	e->brush = (t_brush){200, 100, &linear_interpolation, 5};
}

int				init_env(t_env *e)
{
	mlx_do_key_autorepeaton(e->mlx);
	return (0);
}
