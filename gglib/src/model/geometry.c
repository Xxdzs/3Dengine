/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 18:14:08 by angagnie          #+#    #+#             */
/*   Updated: 2016/05/19 12:46:23 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

t_vec3t		*vec3_alloc(const t_real a, const t_real b, const t_real c)
{
	t_vec3t	*ans;

	ans = (t_vec3t *)malloc(sizeof(t_vec3));
	*ans = NEW_VEC3(a, b, c);
	return (ans);
}

void		vec3_ensure_carth(t_vec3t *v)
{
	if (v->type == CYLINDRICAL)
		cylin2carth(v);
	if (v->type == SPHERICAL)
		spher2carth(v);
}
