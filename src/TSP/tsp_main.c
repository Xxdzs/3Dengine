/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsp_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 20:11:01 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/09 14:24:38 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

int		tsp_submain(t_env *w, int ac, char **av)
{
	if (ac > 0)
		w->tsp.n = ft_atoi(av[0]);
	else
		w->tsp.n = 10;
	w->tsp;
	return (0);
}

int		the_main(int ac, char **av)
{
	ggl_main(ac, av, &tsp_submain);
	return (0);
}
