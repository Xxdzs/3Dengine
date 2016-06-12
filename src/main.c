/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:01:33 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/12 15:17:18 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

#include <stdio.h>

/*
** Default main
*/

int		main(int ac, char **av)
{
	ft_putstr("\e[1;1H\e[2J\t\t--=== Launching ");
	ft_putstr(*av);
	ft_putstr(" ===--\n");
	return (frac_main(--ac, ++av));
}
