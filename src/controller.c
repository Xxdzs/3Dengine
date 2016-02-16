/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:17:13 by angagnie          #+#    #+#             */
/*   Updated: 2016/02/16 17:53:17 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		key_hook(int keycode, void *param)
{
	t_work	*w = param;

	ft_putstr("Key Pressed : ");
	ft_putnbr(keycode);
	ft_putendl("");

	if (keycode == 53)
		exit(1);
	repaint(w);
	return (0);
}
