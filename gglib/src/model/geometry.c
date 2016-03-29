/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 18:14:08 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/27 18:45:07 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		vec3_ensure_carth(t_vec3t *v)
{
	if (v->type == CYLINDRICAL)
		cylin2carth(v);
	if (v->type == SPHERICAL)
		spher2carth(v);
}

