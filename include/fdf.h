/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:39:13 by angagnie          #+#    #+#             */
/*   Updated: 2016/02/16 19:22:17 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <libft.h>
# include <unistd.h>
# include <stdlib.h>

# include "geometry.h"
# include "algebra.h"

typedef struct	s_work
{
	void	*mlx;
	void	*win;
	void	*img;
	t_vec2i	wdim;
	char	*pixel;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}				t_work;

/*
** -----===== Graphics =====-----
** Theta : rotation along the y axis
** Phi : rotation along the x axis
** Sigma : rotation along the z axis
*/

typedef struct	s_grfx
{
	float		theta;
	float		phi;
	float		sigma;
}

int				expose_hook(void *param);
int				key_hook(int keycode, void *param);
void			repaint(t_work *const w);

#endif
