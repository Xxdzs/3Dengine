/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:01:23 by angagnie          #+#    #+#             */
/*   Updated: 2016/02/16 18:18:43 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		expose_hook(void *param)
{
	t_work *w = param;

	ft_putstr("Exposing\n");
	mlx_clear_window(w->mlx, w->win);
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	return (0);
}

void	repaint(t_work *const w)
{
	int		i;

	ft_putstr("Repainting\n");
	i = 2000;
	while (i-- > 0)
		w->pixel[(i / 100) * w->line_size + i % 100] = 100;
	expose_hook(w);
}
