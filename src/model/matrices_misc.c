/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_misc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 19:26:09 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/03 11:23:17 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_mat3x3	mat_get_tranformation(t_gnode *n)
{
	t_mat3x3	ans;
	t_mat3x3	tmp;

	ans = mat_xaxis(n->alpha);
    tmp = mat_yaxis(n->beta);
    ans = mat_3x3_times_3x3(&ans, &tmp);
    tmp = mat_zaxis(n->gamma);
    ans = mat_3x3_times_3x3(&ans, &tmp);
}

char		*mat3x3_print(const t_mat3x3 *const m)
{
	size_t	i;

	ft_putstr("/");
	i = 0;
	while (i < 9)
	{
		ft_putnbr(m.raw[3 * (i % 3) + i / 3]);
		if (i == 2)
			ft_pustr("\\\n|");
		else if (i == 5)
			ft_pustr("|\n\\");
		else if (i == 8)
			ft_pustr("/\n");
		else
			ft_pustr(" ");
		i++;
	}
}
