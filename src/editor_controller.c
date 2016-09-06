/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:17:13 by angagnie          #+#    #+#             */
/*   Updated: 2016/09/06 06:18:28 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ggl.h"

static void		part1(int keycode, t_env *w)
{
	if (keycode == KEY_ESC)
		exit(destroy_env(w));
}

/*
static void		part2(int keycode, t_env *w)
{
}

static void		part3(int keycode, t_env *w)
{
}
*/

int				editor_key_hook(int keycode, void *param)
{
	t_env	*const w = param;

	part1(keycode, w);
//	part2(keycode, w);
//	part3(keycode, w);
	w->fnct.repaint(w);
	w->fnct.expose(w);
	return (0);
}
