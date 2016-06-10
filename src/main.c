/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:01:33 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/10 16:10:00 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

#include <stdio.h>

/*
** Default main
*/

int		main(int ac, char **av)
{
	if (ac > 1)
		ggl_main(ac, av);
	else
		ft_putstr("Usage :\t./fractol julia\n\t\t./fractol mandelbrot");
	return (0);
}
