/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:39:13 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/10 16:27:43 by angagnie         ###   ########.fr       */
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

# include "settings.h"
# include "libft.h"
# include "geometry.h"
# include "matrices.h"
# include "system_tree.h"

# define PIXEL(X,Y) w->pixel[(Y) * w->line_size + (X) * (w->bits_per_pixel / 8)]

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
	t_real		ratio;
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
	int			bonus;
}				t_env;

int				default_expose_hook(void *param);
int				default_key_hook(int keycode, void *param);
int				default_repaint(t_env *const w);
int				read_av(t_obj *w, int length, char **param);
t_real			ft_ator(char *str);
int				ggl_main(int ac, char **av);
int				render(t_env *const w);
int				linear_interpolation(int const i,
					int const dout, int const din);
int				smooth_interpolation(int const i,
					int const dout, int const din);
int				ez_interpolation(int const i,
					int const dout, int const din);
int				interpolate(t_env *const w, const t_pnt2i *p1,
					const t_pnt2i *p2, const t_fnptr algo);
int				draw_line(t_env *const w, t_pnt2i *p1, t_pnt2i *p2);
int				parse_fdf(t_obj *w, int fd);
int				parse_obj(t_obj *w, int fd);
t_mat3x3		mat_get_transformation(t_gnode *n);
t_mat4x4		mat4_get_transformation(t_gnode *n);
t_gnode			*obj_adjust(t_obj *o);
void			vrtx_offset(t_real *x, t_real *y, t_vrtx *v);
void			obj_reset(t_obj *o);

#endif
