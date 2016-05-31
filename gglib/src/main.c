/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:01:33 by angagnie          #+#    #+#             */
/*   Updated: 2016/05/29 17:55:13 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

#include <stdio.h>

/*
** Default main
*/

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;

//	ggl_main(ac, av);
	char	*str;
	t_qtrn a = NEW_QTRN(1,1,1,0);
	t_qtrn b = {SPHERICAL, {{1, M_PI_2, M_PI_2, M_PI}}};

	printf("a = %s\n", str = qtrn_to_string(&a));free(str);
	perso2rqtrn(&b);
	printf("b = %s\n", str = qtrn_to_string(&b));free(str);
	spher2carth((t_vec3t *)&b);
	printf("b = %s\n", str = qtrn_to_string(&b));free(str);
	t_qtrn c = qtrn_get_rotated(&a, &b);
	printf("c = %s (%f, %f, %f)\n", str = qtrn_to_string(&c), X(c), Y(c), Z(c));
	free(str);
	return (0);
}
