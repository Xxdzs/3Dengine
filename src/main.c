/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:36:43 by angagnie          #+#    #+#             */
/*   Updated: 2016/02/16 18:17:55 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --
#include <stdio.h>
// --
#include <fdf.h>

static void		destroy_work(t_work *const w)
{
	mlx_destroy_image(w->mlx, w->img);
	mlx_destroy_window(w->mlx, w->win);
	ft_putstr("Clear\n");
}

static int	init_work(t_work *const w)
{
	w->wdim = (t_vec2i){{1280, 720}};
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
//	mlx_key_hook(w->win, &key_hook, (void *)w);
	mlx_hook(w->win, 2, 0, &key_hook, (void *)w);
	mlx_do_key_autorepeaton(w->mlx);
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
