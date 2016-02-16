/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:36:43 by angagnie          #+#    #+#             */
/*   Updated: 2016/02/16 15:34:29 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --
#include <stdio.h>
// --
#include <fdf.h>
#include <mlx.h>
#include <libft.h>

int		init_work(t_work *w)
{
	w->wdim = (t_vec2i){{1280, 720}};
	w->mode = 1;
	if (!(w->mlx = mlx_init()))
		return (1);
	ft_putstr("Librairy Initialised\n");
	if (!(w->win = mlx_new_window(w->mlx, w->wdim.d.width, w->wdim.d.height, "Fil De Fer")))
		return (2);
	ft_putstr("Window Created\n");
	return (0);
}

int		main(int ac, char **av)
{
	t_work	w;

	(void)ac;
	(void)av;
	init_work(&w);
	return (0);
}
