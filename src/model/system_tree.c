/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <sid@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 14:10:06 by sid               #+#    #+#             */
/*   Updated: 2016/03/06 12:56:30 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system_tree.h"
#include <stdlib.h>

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

t_obj		*obj_alloc(char *str)
{
	t_obj	*ans;

	ans = (t_obj *)gnode_alloc(sizeof(t_obj));
	ans->vertices = ft_dyna_new(sizeof(t_vrtx));
	ft_dyna_datainit(&ans->vertices);
	ans->faces = ft_dyna_new(sizeof(t_face));
	ft_dyna_datainit(&ans->faces);
	if (!(ans->name = ft_strdup(str)))
	{
		write(2, "Malloc failed : Exiting\n", 24);
		exit(1);
	}
	ans->dim = 0;
	return (ans);
}

t_camera	*camera_alloc(void)
{
	t_camera *ans;

	ans = (t_camera *)gnode_alloc(sizeof(t_obj));
	ans->fov = 60;
	ans->ratio = (t_pnt2i){16, 9};
	return(ans);
}

t_obj		obj_new(char *str)
{
	t_obj	ans;

	ftl_init((t_list *)&ans.node, sizeof(t_obj));
	ans.node.parent = NULL;
	ans.pos = (t_vec3){{0, 0, 0}};
	ans.rot = (t_qtrn){{0, 0, 0, 0}};
	ans.vertices = ft_dyna_new(sizeof(t_vrtx));
	ft_dyna_datainit(&ans.vertices);
	ans.faces = ft_dyna_new(sizeof(t_vrtx));
	ft_dyna_datainit(&ans.faces);
	if (!(ans.name = ft_strdup(str)))
	{
		write(2, "Malloc failed : Exiting\n", 24);
		exit(1);
	}
	ans.dim = 0;
}

/*
** -----===== Methods =====-----
*/

void		gnode_add_child(t_gnode *parent, t_gnode *child)
{
	child->parent = parent;
	ftl_push_back((t_list *)parent, (t_node *)child);
}
