/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:17:13 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/31 12:56:52 by angagnie         ###   ########.fr       */
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
	if (keycode == 43)			w->g.world->node.rot.d.s++;
	else if (keycode == 43)		w->g.world->node.rot.d.s--;
	else if (keycode == 53)		exit(0);
	else if (keycode == 69)		w->g.world->node.scale *= 1.25;
	else if (keycode == 71)		w->g.world->node.scale *= 0.8;
	else if (keycode == 123)	THETA(w->g.world->node.rot.d.v)++;
	else if (keycode == 124)	THETA(w->g.world->node.rot.d.v)--;
	else if (keycode == 125)	PHI(w->g.world->node.rot.d.v)++;
	else if (keycode == 126)	PHI(w->g.world->node.rot.d.v)--;
	w->fnct.repaint(w);
	w->fnct.expose(w);
	return (0);
}