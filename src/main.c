/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:01:33 by angagnie          #+#    #+#             */
/*   Updated: 2016/09/08 00:45:27 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

#include <stdio.h>

/*
** Default main
*/

int		main(int ac, char **av)
{
	db_putstr("\e[1;1H\e[2J\t\t --=== Starting ===--");
	db_putstr(*av);
	return (the_main(--ac, ++av));
}
