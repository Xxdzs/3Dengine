/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <sid@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 14:10:06 by sid               #+#    #+#             */
/*   Updated: 2016/03/03 17:17:01 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** -----===== Constructors =====-----
*/

t_gnode		*gnode_alloc(size_t type_size)
{
	t_gnode		*ans;

	ans = (t_gnode *)malloc(type_size);
	ftl_init((t_list *)ans, type_size);
	ans->parent = NULL;
	ans->pos = (t_vec3){{0, 0, 0}};
	ans->rot = (t_qtrn){{0, 0, 0, 0}};
	return (ans);
}

t_obj		*obj_alloc(void)
{
	t_obj	*ans;

	ans = (t_obj *)gnode_alloc(sizeof(t_obj));
	ans->vertices = ft_dyna_new(sizeof(t_vrtx));
	ft_dyna_datainit(&ans->vertices);
	ans->faces = ft_dyna_new(sizeof(t_face));
	ft_dyna_datainit(&ans->faces);
	return (ans);
}

/*
** -----===== Methods =====-----
*/

void		gnode_add_child(t_gnode *parent, t_gnode *child, t_vec3 pos)
{
	child->parent = parent;
	ftl_push_back((t_list *)parent, (t_node *)child);
	child->pos = pos;
	child->rot = (t_qtrn){{1, 0, 0, 0}};
}
