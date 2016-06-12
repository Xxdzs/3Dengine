/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <angagnie@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:48:37 by sid               #+#    #+#             */
/*   Updated: 2016/06/12 23:07:48 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

int					read_av(t_obj *w, int length, char **param)
{
	char			*ext;
	int				i;
	unsigned int	t;
	int				fd;
	const void		*tab[] = {"fdf", &parse_fdf, "obj", &parse_obj};

	i = -1;
	while (++i < length)
	{
		ext = ft_strrchr(param[i], '.');
		if (ext++ == NULL)
			exit(0);
		t = 0;
		while (t < 4 && ft_strcmp(ext, tab[t]))
			t += 2;
		if (t == 4)
			exit(0);
		else if ((fd = open(param[i], O_RDONLY)) == -1
			|| ((int (*)(t_obj *, int))(tab[t + 1]))(w, fd))
			return (1);
		exit(0);
	}
	return (0);
}
