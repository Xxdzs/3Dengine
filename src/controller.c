/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:17:13 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/07 00:13:31 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ggl.h"

static void		part1(int keycode, t_env *w)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_PLUS)
		((t_gnode *)w->g.world->node.children.root.next)->scale *= 1.25;
	else if (keycode == KEY_MINUS)
		((t_gnode *)w->g.world->node.children.root.next)->scale *= 0.8;
	else if (keycode == KEY_LEFT)
		X(((t_gnode *)w->g.world->node.children.root.next)->pos) -= 5;
	else if (keycode == KEY_RIGHT)
		X(((t_gnode *)w->g.world->node.children.root.next)->pos) += 5;
	else if (keycode == KEY_DOWN)
		Z(((t_gnode *)w->g.world->node.children.root.next)->pos) += 5;
	else if (keycode == KEY_UP)
		Z(((t_gnode *)w->g.world->node.children.root.next)->pos) -= 5;
	else if (keycode == KEY_KP_5)
		obj_reset((t_obj *)w->g.world->node.children.root.next);
}

static void		part2(int keycode, t_env *w)
{
	if (keycode == KEY_KP_7)
		((t_gnode *)w->g.world->node.children.root.next)->gamma += 0.1;
	else if (keycode == KEY_KP_9)
		((t_gnode *)w->g.world->node.children.root.next)->gamma -= 0.1;
	else if (keycode == KEY_KP_4)
		((t_gnode *)w->g.world->node.children.root.next)->beta -= 0.1;
	else if (keycode == KEY_KP_6)
		((t_gnode *)w->g.world->node.children.root.next)->beta += 0.1;
	else if (keycode == KEY_KP_2)
		((t_gnode *)w->g.world->node.children.root.next)->alpha += 0.1;
	else if (keycode == KEY_KP_8)
		((t_gnode *)w->g.world->node.children.root.next)->alpha -= 0.1;
	else if (keycode == KEY_CH_RIGHT)
		w->bonus++;
	else if (keycode == KEY_CH_LEFT)
		w->bonus--;
}

int				default_key_hook(int keycode, void *param)
{
	t_env	*const w = param;

	ft_putstr("Key Pressed : ");
	ft_putnbr(keycode);
	ft_putendl("");
	part1(keycode, w);
	part2(keycode, w);
	w->fnct.repaint(w);
	w->fnct.expose(w);
	return (0);
}
