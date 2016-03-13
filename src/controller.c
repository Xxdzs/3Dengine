/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:17:13 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/13 13:23:06 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

int		default_key_hook(int keycode, void *param)
{
	t_env	*const w = param;

	ft_putstr("Key Pressed : ");
	ft_putnbr(keycode);
	ft_putendl("");
	if (keycode == 53)
		exit(1);
	w->fnct.repaint(w);
	w->fnct.expose_hook(w);
	return (0);
}
