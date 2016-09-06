/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:01:33 by angagnie          #+#    #+#             */
/*   Updated: 2016/09/05 17:38:53 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

#include <stdio.h>

/*
** Default main
*/

#ifdef DEBUG

int		main(int ac, char **av)
{
	ft_putstr("\e[1;1H\e[2J\t\t--=== Launching ");
	ft_putstr(*av);
	ft_putstr(" ===--\n");
	return (the_main(--ac, ++av));
}

#else

int		main(int ac, char **av)
{
	return (the_main(--ac, ++av));
}

#endif
