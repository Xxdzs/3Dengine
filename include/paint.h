/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 06:09:08 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/24 06:32:58 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAINT_H
# define PAINT_H

# include "ggl.h"

# define NEW_COLOR_ARGB(A,R,G,B) ((A << 24) + (R << 16) + (G << 8) + B)
# define NEW_COLOR_RGB(R,G,B) NEW_COLOR_ARGB(0,R,G,B)

void	pxl_on(t_img *w, t_pnt2i p, unsigned color);
void	plot_on(t_img *w, t_brush *b, t_pnt2i p);
int		interpolate(t_img *w, t_brush *b, t_pnt2i p1, t_pnt2i p2);
int		draw_line(t_img *w, t_brush *b, t_pnt2i p1, t_pnt2i p2);

#endif
