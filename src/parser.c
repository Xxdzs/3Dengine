/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <sid@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:48:37 by sid               #+#    #+#             */
/*   Updated: 2016/02/27 23:22:29 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse_fdf(char *filename)
{
	;
}

void	parse_obj(char *filename)
{
	;
}

int		read_av(int length, char **param)
{
	char			*c;
	int				i;
	unsigned int	t;
	const void		*tab[] = {"fdf", &parse_fdf, "obj", &parse_obj};

	i = length;
	while (i-- > 0)
	{
		c = param[i];
		while (*c++ != '.')
			;
		t = 0;
		while (t < sizeof(tab) && ft_strcmp(c, tab[t]))
			t += 2;
		if (t == sizeof(tab))
			return (1);
		else
			((void (*)(char *))(tab[t - 1]))(param[i]);
	}
	return (0);
}
