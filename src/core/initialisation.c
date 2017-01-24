/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:36:43 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/24 05:39:32 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

void			destroy_env(t_env * e)
{
	mlx_destroy_image(w->mlx, w->img);
	mlx_destroy_window(w->mlx, w->win);
	w->fnct.free(w);
	db_putstr("\t\t--==  Clear  ==--");
}

void			init_fnct_env(t_env *e)
{
	init_fnct(&e->win, &e->fnct, (void *)e);
}

void			init_fnct(t_win *w, t_fnct *f, void *e)
{
	mlx_expose_hook(w->data, f->expose, e);
	mlx_hook(w->data, 2, 0, f->key_hook, e);
	mlx_hook(w->data, 6, 4, f->mouse_move, e);
	mlx_mouse_hook(w->data, f->mouse_click, e);
}

void			default_values(t_env *e)
{

}

int				init_env(t_env *e)
{
	mlx_do_key_autorepeaton(e->mlx);
	return (0);
}
