/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:39:13 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/24 05:40:01 by angagnie         ###   ########.fr       */
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
# include "debug.h"

/*
** # define PIXEL(X,Y)
** |	w->pixel[(Y) * w->line_size + (X) * (w->bits_per_pixel / 8)]
** # define NEW_COLOR_ARGB(A,R,G,B) ((A << 24) + (R << 16) + (G << 8) + B)
** # define NEW_COLOR_RGB(R,G,B) NEW_COLOR_ARGB(0,R,G,B)
*/

typedef int		(*t_fnptr)();

typedef struct	s_win
{
	void		*data;
	t_vec2i		dim;
	t_real		ratio;
}				t_win;

typedef struct	s_img
{
	void		*data;
	t_vec2i		dim;
	t_real		ratio;
	char		*pixel;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_img;

typedef struct	s_fnct
{
	t_fnptr		repaint;
	t_fnptr		key_hook;
	t_fnptr		expose;
	t_fnptr		mouse_click;
	t_fnptr		mouse_move;
	t_fnptr		free;
}				t_fnct;

typedef struct	s_brush
{
	unsigned	color;
	unsigned	color2;
	t_fnptr		easing;
	uint8_t		size;
}				t_brush;

typedef struct	s_env
{
	void		*mlx;
	t_win		win;
	t_img		img;
	t_fnct		fnct;
	t_brush		brush;
}				t_env;

int				the_main(int ac, char **av);
int				ggl_main(t_env *w);

int             init_env(t_env *w);
void			init_fnct_env(t_env *e);
void			init_fnct(t_win *w, t_fnct *f, void *e);
void			destroy_env(t_env *w);

int				default_expose_hook(void *param);
int				default_key_hook(int keycode, void *param);
int				default_mouse_hook(int button, int x, int y, void *param);
int				default_mouse_move_hook(int x, int y, void *param);
int				default_repaint(t_env *w);

#endif
