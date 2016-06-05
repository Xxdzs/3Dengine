/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_misc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 19:26:09 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/05 14:18:57 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"
#include "ggl.h"

t_mat3x3	mat_get_transformation(t_gnode *n)
{
	t_mat3x3	ans;
	t_mat3x3	tmp;

	ans = mat_scale(n->scale);
    tmp = mat_xaxis(n->alpha);
    ans = mat_3x3_times_3x3(&ans, &tmp);
    tmp = mat_yaxis(n->beta);
    ans = mat_3x3_times_3x3(&ans, &tmp);
    tmp = mat_zaxis(n->gamma);
    ans = mat_3x3_times_3x3(&ans, &tmp);
	return (ans);
}

void		mat3x3_print(const t_mat3x3 *const m)
{
	size_t	i;
	t_real	n;

	ft_putstr("/");
	i = 0;
	while (i < 9)
	{
		ft_putnbr(n = m->raw[3 * (i % 3) + i / 3]);
		ft_putchar('.');
		ft_putnbr((int)((n - trunc(n)) * 10000));
		if (i == 2)
			ft_putstr("\\\n|");
		else if (i == 5)
			ft_putstr("|\n\\");
		else if (i == 8)
			ft_putstr("/\n");
		else
			ft_putstr(" ");
		i++;
	}
}
