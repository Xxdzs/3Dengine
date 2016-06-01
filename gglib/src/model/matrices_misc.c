/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_misc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 19:26:09 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/01 19:39:19 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*mat3x3_print(const t_mat3x3 *const m)
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
