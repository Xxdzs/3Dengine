/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <sid@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 14:10:06 by sid               #+#    #+#             */
/*   Updated: 2016/05/31 17:36:26 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

/*
** -----===== Member Functions =====-----
*/

void		gnode_add_child(t_gnode *parent, t_gnode *child)
{
	child->parent = parent;
	if (ftl_push_back((t_list *)parent, (t_node *)child))
		ft_exit("gnode_add_child", "Out of memory (malloc failed)");
}

int			obj_add_center(t_gnode *parent, t_obj *child)
{
	t_obj	tmp;

	if (child->dim == NULL)
	{
		gnode_add_child(parent, (t_gnode *)child);
		return (1);
	}
	tmp = obj_new(ft_strjoin(child->name, "_center"));
	ft_memcpy(&tmp.node.pos, &child->node.pos, sizeof(t_vec3));
	gnode_add_child(parent, (t_gnode *)&tmp);
	gnode_add_child((t_gnode *)&tmp, (t_gnode *)child);
	return (0);
}

t_obj		*obj_find(const t_obj *const node, const char *const name)
{
	t_node	*tmp;
	t_obj	*ans;

	if (node->name && name && ft_strcmp(node->name, name) == 0)
		return ((t_obj *)node);
	if (node->node.children.size > 0)
	{
		tmp = (t_node *)&(node->node.children);
		while ((tmp = tmp->next) != &(node->node.children.root))
			if ((ans = obj_find((t_obj *)tmp, name)) != NULL)
				return (ans);
	}
	return (NULL);
}
