/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 08:20:52 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/26 03:34:08 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"
#include "easings.h"

int				img_new(void *mlx, t_img *w, t_vec2i dim)
{
	w->dim = dim;
	w->ratio = (t_real)dim.c.x / (t_real)dim.c.y;
	if (!(w->data = mlx_new_image(mlx, dim.d.width, dim.d.height)))
		return (1);
	w->pixel = mlx_get_data_addr(w->data, &w->bits_per_pixel,
		&w->line_size, &w->endian);
	db_putstr("Image created.");
	return (0);
}

int				win_new(void *mlx, t_win *w, t_vec2i dim)
{
	w->dim = dim;
	w->ratio = (t_real)dim.c.x / (t_real)dim.c.y;
	if (!(w->data = mlx_new_window(mlx, dim.d.width, dim.d.height, "Wolf 3D")))
		return (1);
	db_putstr("Window created.");
	return (0);
}

void			env_new(t_env *e)
{
	db_putstr("env_new");
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
