/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <angagnie@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:48:37 by sid               #+#    #+#             */
/*   Updated: 2017/01/24 00:03:46 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

int					read_files(t_obj *w, int length, char **param)
{
	char			*ext;
	int				i;
	unsigned int	t;
	int				fd;
	const void		*supported_formats[] = {SUPPORTED_FORMATS};

	i = -1;
	while (++i < length)
	{
		ext = ft_strrchr(param[i], '.');
		if (ext++ == NULL)
			exit(0);
		t = 0;
		while (t < 4 && ft_strcmp(ext, supported_formats[t]))
			t += 2;
		if (t == 4)
			exit(0);
		else if ((fd = open(param[i], O_RDONLY)) == -1
			|| ((int (*)(t_obj *, int))(supported_formats[t + 1]))(w, fd))
			return (1);
		exit(0);
	}
	return (0);
}
