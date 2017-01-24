/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:36:43 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/24 05:34:48 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

int				ggl_main(t_env *w)
{
	if (init_env(w))
		ft_putstr_fd("Error : Initialisation failed\n", 2);
	else
	{
		init_fnct_env(w);
		w->fnct.repaint(w);
		mlx_loop(w->mlx);
		destroy_env(w);
	}
	return (0);
}
