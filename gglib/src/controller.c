/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:17:13 by angagnie          #+#    #+#             */
/*   Updated: 2016/05/31 22:42:44 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

/*
** |		Key codes :
** |	53 :	Esc.	escape
** |	69 :	+		plus
** |	78 :	-		minus
** |	123 :	<-		left
** |	124 :	->		right
** |	125 :	\/		down
** |	126 :	/\		up
*/

int		default_key_hook(int keycode, void *param)
{
	t_env	*const w = param;

	ft_putstr("Key Pressed : ");
	ft_putnbr(keycode);
	ft_putendl("");
#ifdef EULER
	if (keycode == 43)			w->g.world->node.alpha++; // <
	else if (keycode == 47)		w->g.world->node.alpha--; // >
	else if (keycode == 53)		exit(0); // esc
	else if (keycode == 69)		w->g.world->node.scale *= 1.25; // +
	else if (keycode == 78)		w->g.world->node.scale *= 0.8; // -
	else if (keycode == 123)	w->g.world->node.beta++; // <-
	else if (keycode == 124)	w->g.world->node.beta--; // ->
	else if (keycode == 125)	w->g.world->node.gamma++; // \/
	else if (keycode == 126)	w->g.world->node.gamma--; // /\...
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
	w->fnct.repaint(w);
	w->fnct.expose(w);
	return (0);
}
