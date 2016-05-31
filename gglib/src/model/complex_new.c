/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:48:32 by angagnie          #+#    #+#             */
/*   Updated: 2016/05/31 17:32:15 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_cmplx		cmplx_cpy(const t_cmplx *const c, const t_type t)
{
	t_cmplx		ans;

	ans = *c;
	if (c->type == CARTHESIAN && t == POLAR)
		carth2polar(&ans);
	else if (c->type == POLAR && t == CARTHESIAN)
		polar2carth(&ans);
	return (ans);
}
