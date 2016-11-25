/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:17:13 by angagnie          #+#    #+#             */
/*   Updated: 2016/09/08 00:35:58 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ggl.h"

int				default_key_hook(int keycode, void *param)
{
	t_env	*const w = param;

	db_putvalue("Key Pressed : ", keycode, "");
	w->fnct.repaint(w);
	w->fnct.expose(w);
	return (0);
}
