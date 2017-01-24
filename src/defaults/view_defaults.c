/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_defaults.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:01:23 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/24 06:30:46 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"
#include "paint.h"

int			default_expose_hook(void *param)
{
	t_env *const	e = param;

	mlx_put_image_to_window(e->mlx, e->win.data, e->img.data, 0, 0);
	return (0);
}

int			default_repaint(t_env *const e)
{
	db_putstr("Repainting, but no custom repainting function provided");
	draw_line(&e->img, &e->brush, (t_pnt2i){100, 100}, (t_pnt2i){600, 400});
	draw_line(&e->img, &e->brush, (t_pnt2i){600, 400}, (t_pnt2i){600, 100});
	draw_line(&e->img, &e->brush, (t_pnt2i){400, 100}, (t_pnt2i){100, 100});
	return (0);
}
