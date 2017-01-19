/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:39:13 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/19 11:53:25 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GGL_H
# define GGL_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <sys/wait.h>
# include "mlx.h"
# include "settings.h"
# include "libft.h"
# include "geometry.h"
# include "matrices.h"
# include "system_tree.h"

# define PIXEL(X,Y) w->pixel[(Y) * w->line_size + (X) * (w->bits_per_pixel / 8)]
# define NEW_COLOR_ARGB(A,R,G,B) ((A << 24) + (R << 16) + (G << 8) + B)
# define NEW_COLOR_RGB(R,G,B) NEW_COLOR_ARGB(0,R,G,B)
# define UINT unsigned

typedef int		(*t_fnptr)();
typedef UINT	(*t_fnray)();

typedef struct	s_env
{
	t_grfx		g;
	void		*mlx;
	void		*win;
	void		*img;
	t_vec2i		wdim;
	t_real		ratio;
	char		*pixel;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
	struct
	{
		t_fnptr	repaint;
		t_fnptr	key_hook;
		t_fnptr	expose;
		t_fnptr	mouse_click;
		t_fnptr	mouse_move;
		t_fnray	raytrace;
	}			fnct;
	struct
	{
		UINT	color;
		char	line_style;
		char	gap;
	}			draw;
}				t_env;

# undef UINT

int				the_main(int ac, char **av);

void			init_fnct(t_env *const w);
int				default_expose_hook(void *param);
int				default_key_hook(int keycode, void *param);
int				default_mouse_hook(int button, int x, int y, void *param);
int				default_mouse_move_hook(int x, int y, void *param);
int				default_repaint(t_env *w);
int				destroy_env(t_env *const w);
int				read_av(t_obj *w, int length, char **param);
t_real			ft_ator(char *str);
int				ggl_main(t_env *w, int ac, char **av, t_fnptr submain);
int				render(t_env *w);
int				raytrace(void *w);
void			pxl_on(t_env *w, int x, int y, unsigned int color);
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

void			db_putstr(char const *str);
void			db_putvalue(char const *str, int n, char const *end);

unsigned		stripes1(t_env *w, t_pnt2i p, t_pnt2i d);
unsigned		stripes2(t_env *w, t_pnt2i p, t_pnt2i d);
unsigned		stripes3(t_env *w, t_pnt2i p, t_pnt2i d);
unsigned		stripes4(t_env *w, t_pnt2i p, t_pnt2i d);

#endif
