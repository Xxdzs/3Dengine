/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_tree_misc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <angagnie@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 14:10:06 by sid               #+#    #+#             */
/*   Updated: 2016/06/05 19:51:21 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

void	vrtx_transform(const t_mat4x4 *m, t_vrtx *v)
{
	t_mat4x1	tmp;

	tmp = (t_mat4x1){{X(v->vec), Y(v->vec), Z(v->vec), 1}};
	tmp = mat_4x4_times_4x1(m, &tmp);
	X(v->vec) = tmp.c.x;
	Y(v->vec) = tmp.c.y;
	Z(v->vec) = tmp.c.z;
}

t_obj	*obj_find(const t_gnode *const node, const char *const name)
{
	t_node	*tmp;
	t_obj	*ans;

	if (node->is_obj && ((t_obj *)node)->name && name
		&& ft_strcmp(((t_obj *)node)->name, name) == 0)
		return ((t_obj *)node);
	if (node->children.size > 0)
	{
		tmp = (t_node *)&(node->children.root);
		while ((tmp = tmp->next) != &(node->children.root))
			if ((ans = obj_find((t_gnode *)tmp, name)) != NULL)
				return (ans);
	}
	return (NULL);
}
