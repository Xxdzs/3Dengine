/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:39:13 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/01 16:43:31 by sid              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef double		t_real;

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <sys/wait.h>

# ifdef X11
#  include <X11/Xlib.h>
# else
#  include "mlx.h"
# endif

# include "libft.h"
# include "geometry.h"
# include "algebra.h"
# include "system_tree.h"

typedef struct	s_work
{
# ifdef X11
	Display	*disp;
	Window	*win;
	XImage	img;
# else
	void	*mlx;
	void	*win;
	void	*img;
# endif
	t_vec2i	wdim;
	char	*pixel;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}				t_work;

int				expose_hook(void *param);
int				key_hook(int keycode, void *param);
void			repaint(t_work *const w);

#endif
