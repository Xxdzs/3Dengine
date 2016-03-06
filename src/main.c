/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:36:43 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/06 13:25:12 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		destroy_env(t_env *const w)
{
#ifdef X11
	XCloseDisplay(w->disp);
	free(w->win);
#else
	mlx_destroy_image(w->mlx, w->img);
	mlx_destroy_window(w->mlx, w->win);
#endif
	ft_putstr("Clear\n");
}

static int	init_env(t_env *const w)
{
#ifdef X11
	int		sd;
#endif

	w->wdim = (t_vec2i){{1280, 720}};
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
	if (!(w->win = mlx_new_window(w->mlx, w->wdim.d.width, w->wdim.d.height, "Fil De Fer")))
		return (2);
	ft_putstr("Window Created\n");
	if (!(w->img = mlx_new_image(w->mlx, w->wdim.d.width, w->wdim.d.height)))
		return (3);
	ft_putstr("Image Allocated\n");
	if (!(w->pixel = mlx_get_data_addr(w->img, &(w->bits_per_pixel), &(w->line_size), &(w->endian))))
		return (4);
	ft_putstr("Image informations Obtained\n");
	mlx_expose_hook(w->win, &expose_hook, (void *)w);
	mlx_hook(w->win, 2, 0, &key_hook, (void *)w);
	mlx_do_key_autorepeaton(w->mlx);
#endif
	w->g.world = obj_alloc("World");
	w->g.cam = camera_alloc();
	repaint(w);
	return (0);
}

int			main(int ac, char **av)
{
	t_env	w;
#ifdef X11
	XEvent event;
#endif

	(void)ac;
	(void)av;
	if (init_env(&w))
		ft_putstr_fd("Error : Initialisation failed\n", 2);
	read_av(w, ac - 1, av + 1);
#ifdef X11
	else {
		do {
			XNextEvent(w.disp, &event);
			if (event.type == Expose)
				expose_hook(&w);
			else if (event.type == KeyPress)
				key_hook(event.xkey.keycode, &w);
		} while (event.type == KeyPress && event.xkey.keycode == 53);
#else
	else if (fork())
		mlx_loop(w.mlx);
	else
	{
		wait(0);
#endif
		ft_putstr("Loop killed\n");
		destroy_env(&w);
	}
	return (0);
}
