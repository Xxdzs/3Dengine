/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:36:43 by angagnie          #+#    #+#             */
/*   Updated: 2016/02/24 15:30:25 by sid              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		destroy_work(t_work *const w)
{
#ifdef X11
	XCloseDisplay(w->mlx);
	free(w->win);
#else
	mlx_destroy_image(w->mlx, w->img);
	mlx_destroy_window(w->mlx, w->win);
#endif
	ft_putstr("Clear\n");
}

static int	init_work(t_work *const w)
{
	int		sd;

	w->wdim = (t_vec2i){{1280, 720}};
#ifdef X11
	if (!(w->mlx = XOpenDisplay(NULL)))
		return (5);
	ft_putstr("Connected to the X server\n");
	sd = DefaultScreen(w->mlx);
	if (!(w->win = malloc(sizeof(Window))))
		return (6);
	*(w->win) = XCreateSimpleWindow(
		w->mlx, RootWindow(w->mlx, sd), 100, 200,
		w->wdim.d.width, w->wdim.d.height, 2,
		BlackPixel(w->mlx, sd), WhitePixel(w->mlx, sd));
	ft_putstr("Window Created\n");
	XSelectInput(w->mlx, *(w->win), ExposureMask | KeyPressMask);
	XMapWindow(w->mlx, *(w->win));
#else
	(void)sd;
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
	repaint(w);
	return (0);
}

int			main(int ac, char **av)
{
	t_work	w;

	(void)ac;
	(void)av;
	if (init_work(&w))
		ft_putstr_fd("Error : Initialisation failed\n", 2);
	else if (fork())
		mlx_loop(w.mlx);
	else
	{
		wait(0);
		ft_putstr("Loop killed\n");
		destroy_work(&w);
	}
	return (0);
}
