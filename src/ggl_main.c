/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:36:43 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/12 23:28:57 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

int		destroy_env(t_env *const w)
{
#ifdef X11
	XCloseDisplay(w->disp);
	free(w->win);
#else
	mlx_destroy_image(w->mlx, w->img);
	mlx_destroy_window(w->mlx, w->win);
#endif
	ft_putstr("  --==  Clear  ==--\n");
	return (0);
}

static void		init_fnct(t_env *const w)
{
	w->fnct.repaint = default_repaint;
	w->fnct.key_hook = default_key_hook;
	w->fnct.expose = default_expose_hook;
	w->fnct.mouse_click = default_mouse_hook;
	w->fnct.mouse_move = default_mouse_move_hook;
}

static int		init_env(t_env *const w)
{
#ifdef X11
	int		sd;
#endif

	init_fnct(w);
	w->wdim = (t_vec2i){{DEFAULT_RESOLUTION}};
	w->ratio = ((t_real)w->wdim.d.width) / (t_real)w->wdim.d.height;
#ifdef X11
	if (!(w->disp = XOpenDisplay(NULL)))
		return (5);
	ft_putstr("Connected to the X server\n");
	sd = DefaultScreen(w->disp);
	if (!(w->win = malloc(sizeof(Window))))
		return (6);
	*(w->win) = XCreateSimpleWindow(
		w->disp, RootWindow(w->disp, sd), 100, 200,
		w->wdim.d.width, w->wdim.d.height, 2,
		BlackPixel(w->disp, sd), WhitePixel(w->disp, sd));
	ft_putstr("Window Created\n");
	XSelectInput(w->disp, *((Window *)w->win), ExposureMask | KeyPressMask);
	XMapWindow(w->disp, *((Window *)w->win));
#else
	if (!(w->mlx = mlx_init()))
		return (1);
	ft_putstr("Librairy Initialised\n");
	if (!(w->win = mlx_new_window(w->mlx, w->wdim.d.width,
		w->wdim.d.height, "Fractol")))
		return (2);
	ft_putstr("Window Created\n");
	if (!(w->img = mlx_new_image(w->mlx, w->wdim.d.width,
		w->wdim.d.height)))
		return (3);
	ft_putstr("Image Allocated\n");
	if (!(w->pixel = mlx_get_data_addr(w->img,
		&(w->bits_per_pixel), &(w->line_size), &(w->endian))))
		return (4);
	ft_putstr("Image informations Obtained\n");
	mlx_expose_hook(w->win, w->fnct.expose, (void *)w);
	mlx_hook(w->win, 2, 0, w->fnct.key_hook, (void *)w);
	mlx_hook(w->win, 6, 4, w->fnct.mouse_move, (void *)w);
	mlx_mouse_hook(w->win, w->fnct.mouse_click, (void *)w);
	mlx_do_key_autorepeaton(w->mlx);
#endif
	w->bonus = 0;
	return (0);
}

int				ggl_main(int ac, char **av, t_fnptr submain)
{
	t_env	w;
#ifdef X11
	XEvent event;
#endif

	if (init_env(&w))
		ft_putstr_fd("Error : Initialisation failed\n", 2);
	else
	{
		submain(&w, ac, av);
		w.fnct.repaint(&w);
#ifdef X11
		do {
			XNextEvent(w.disp, &event);
			if (event.type == Expose)
				expose_hook(&w);
			else if (event.type == KeyPress)
				key_hook(event.xkey.keycode, &w);
		} while (event.type == KeyPress && event.xkey.keycode == 53);
#else
		ft_putnbr(mlx_loop(w.mlx));
		ft_putstr(" <- mlx_loop\n");
#endif
		ft_putstr("Loop killed\n");
		destroy_env(&w);
	}
	return (0);
}
