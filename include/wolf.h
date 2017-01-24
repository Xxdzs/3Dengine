/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 05:18:16 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/24 07:46:53 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "ggl.h"
# include "fractals.h"

typedef enum	e_block
{
	NONE = 0,
	FLOOR,
	CEIL,
	BOTH,
	PREV,
	NEXT = 8,

	CEILING = CEIL,
	FLOOR_CEILING = BOTH,
	CEILING_FLOOR = BOTH,
	PREVIOUS = PREV
}				t_block;

typedef struct	s_cell
{
	uint8_t		wall;
	uint8_t		texture;
	t_block		block;
}				t_cell;

typedef struct	s_edtr
{
	t_frac		super;
	size_t		tile;
}				t_edtr;

typedef struct	s_wlf
{
	t_frac		super;
	t_vec2i		mdim;
	t_pnt2		pos;
	t_real		dir;
	t_cell		*map;
	t_real		fov;
	t_real		width;
}				t_wlf;

int				editor_repaint(t_edtr *w);
int				editor_key_hook(int keycode, void *param);
int				editor_mouse_click(int button, int x, int y, void *param);
int				editor_mouse_move(int x, int y, void *param);

int				wolf_repaint(t_wlf *w);

#endif
