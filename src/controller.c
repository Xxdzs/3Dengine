/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:17:13 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/01 12:38:00 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

/*
** |		Key codes :
** |	43 :	, <
** |	47 :	. >
** |	53 :	Esc.	escape
** |	69 :	+		plus
** |	78 :	-		minus
** |	83 :	[1]		num. 1
** |	84 :	[2]		num. 2
** |	85 :	[3]		num. 3
** |	86 :	[4]		num. 4
** |	87 :	[5]		num. 5
** |	88 :	[6]		num. 6
** |	89 :	[7]		num. 7
** |	91 :	[8]		num. 8
** |	92 :	[9]		num. 9
** |	123 :	<-		left
** |	124 :	->		right
** |	125 :	\/		down
** |	126 :	/\		up
*/

static void		part1(int keycode, t_env *w)
{
#ifdef EULER
	if (keycode == 43)
		w->g.world->node.alpha += 0.1;
	else if (keycode == 47)
		w->g.world->node.alpha -= 0.1;
	else if (keycode == 53)
		exit(0);
	else if (keycode == 69)
		w->g.world->node.scale *= 1.25;
	else if (keycode == 78)
		w->g.world->node.scale *= 0.8;
	else if (keycode == 86)
		X(((t_gnode *)w->g.world->node.children.root.next)->pos)++;
	else if (keycode == 88)
		X(((t_gnode *)w->g.world->node.children.root.next)->pos)--;
	else if (keycode == 84)
		Y(((t_gnode *)w->g.world->node.children.root.next)->pos)++;
	else if (keycode == 91)
		Y(((t_gnode *)w->g.world->node.children.root.next)->pos)--;
	else if (keycode == 83)
		Z(((t_gnode *)w->g.world->node.children.root.next)->pos)++;
	else if (keycode == 89)
		Z(((t_gnode *)w->g.world->node.children.root.next)->pos)--;
	else if (keycode == 123)
		w->g.world->node.beta += 0.1;
	else if (keycode == 124)
		w->g.world->node.beta -= 0.1;
	else if (keycode == 125)
		w->g.world->node.gamma += 0.1;
	else if (keycode == 126)
		w->g.world->node.gamma -= 0.1;
#else
	if (keycode == 43)			SCALAR(w->g.world->node.rot)++; // <
	else if (keycode == 47)		SCALAR(w->g.world->node.rot)--; // >
	else if (keycode == 53)		exit(0); // esc
	else if (keycode == 69)		w->g.world->node.scale *= 1.25; // +
	else if (keycode == 78)		w->g.world->node.scale *= 0.8; // -
	else if (keycode == 123)	QTHETA(w->g.world->node.rot)++; // <-
	else if (keycode == 124)	QTHETA(w->g.world->node.rot)--; // ->
	else if (keycode == 125)	QPHI(w->g.world->node.rot)++; // \/
	else if (keycode == 126)	QPHI(w->g.world->node.rot)--; // /\...
#endif
}

int				default_key_hook(int keycode, void *param)
{
	t_env	*const w = param;

	ft_putstr("Key Pressed : ");
	ft_putnbr(keycode);
	ft_putendl("");
	part1(keycode, w);
	w->fnct.repaint(w);
	w->fnct.expose(w);
	return (0);
}