/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:36:43 by angagnie          #+#    #+#             */
/*   Updated: 2016/09/12 19:14:51 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

int				destroy_env(t_env *const w)
{
	mlx_destroy_image(w->mlx, w->img);
	mlx_destroy_window(w->mlx, w->win);
	db_putstr("\t\t--==  Clear  ==--");
	return (0);
}

void			init_fnct(t_env *const w)
{
	mlx_expose_hook(w->win, w->fnct.expose, (void *)w);
	mlx_hook(w->win, 2, 0, w->fnct.key_hook, (void *)w);
	mlx_hook(w->win, 6, 4, w->fnct.mouse_move, (void *)w);
	mlx_mouse_hook(w->win, w->fnct.mouse_click, (void *)w);
}

int				init_env(t_env *const w)
{
	w->wdim = (t_vec2i){{DEFAULT_RESOLUTION}};
	w->ratio = ((t_real)w->wdim.d.width) / (t_real)w->wdim.d.height;
	if (!(w->mlx = mlx_init()))
		return (1);
	db_putstr("Librairy Initialised");
	if (!(w->win = mlx_new_window(w->mlx, w->wdim.d.width,
		w->wdim.d.height, "Fractol")))
		return (2);
	db_putstr("Window Created");
	if (!(w->img = mlx_new_image(w->mlx, w->wdim.d.width,
		w->wdim.d.height)))
		return (3);
	db_putstr("Image Allocated");
	if (!(w->pixel = mlx_get_data_addr(w->img,
		&(w->bits_per_pixel), &(w->line_size), &(w->endian))))
		return (4);
	db_putstr("Image informations Obtained");
	w->fnct.repaint = default_repaint;
	w->fnct.key_hook = default_key_hook;
	w->fnct.expose = default_expose_hook;
	w->fnct.mouse_click = default_mouse_hook;
	w->fnct.mouse_move = default_mouse_move_hook;
	init_fnct(w);
	mlx_do_key_autorepeaton(w->mlx);
	return (0);
}

int				ggl_main(int ac, char **av, t_fnptr submain)
{
	t_env	w;

	if (init_env(&w))
		ft_putstr_fd("Error : Initialisation failed\n", 2);
	else
	{
		submain(&w, ac, av);
		init_fnct(&w);
		w.fnct.repaint(&w);
		mlx_loop(w.mlx);
		destroy_env(&w);
	}
	return (0);
}
