/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:36:43 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/24 18:12:20 by angagnie         ###   ########.fr       */
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

int				init_env(t_env *e)
{
	const t_vec2i	d = (t_vec2i){{DEFAULT_RESOLUTION}};

	if (!(e->mlx = mlx_init))
		return (1);
	win_new(e->mlx, &e->win, d);
	img_new(e->mlx, &e->img, d);
	db_putstr("Libraray Initialised.");
	init_fnct_env(e);
	mlx_do_key_autorepeaton(e->mlx);
	return (0);
}
