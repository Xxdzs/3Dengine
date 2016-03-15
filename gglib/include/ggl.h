/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:39:13 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/14 21:48:40 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GGL_H
# define GGL_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <sys/wait.h>

# ifdef X11
#  include <X11/Xlib.h>
# else
#  include "mlx.h"
# endif

# include "libft.h"
# include "geometry.h"
# include "matrices.h"
# include "settings.h"
# include "system_tree.h"

typedef int	(*t_fnptr)();

typedef struct	s_env
{
# ifdef X11
	Display		*disp;
	Window		*win;
	XImage		img;
# else
	void		*mlx;
	void		*win;
	void		*img;
# endif
	t_vec2i		wdim;
	char		*pixel;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
	t_grfx		g;
	struct
	{
		t_fnptr	repaint;
		t_fnptr	key_hook;
		t_fnptr	expose;
	}			fnct;
}				t_env;

int				default_expose_hook(void *param);
int				default_key_hook(int keycode, void *param);
int				default_repaint(t_env *const w);
int				read_av(t_obj *w, int length, char **param);
t_real			ft_ator(char *str);

#endif /* GGL_H */
