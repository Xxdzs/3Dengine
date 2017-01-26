/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:01:33 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/26 07:27:42 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

int		main(int ac, char **av)
{
	int		i;

	db_putstr("\e[1;1H\e[2J\t\t --=== Starting ===--");
	db_putstr(*av);
	i = 0;
	while (++i < ac)
		db_putstr(av[i]);
	return (the_main(--ac, ++av));
}
