/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_tree_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <angagnie@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 14:10:06 by sid               #+#    #+#             */
/*   Updated: 2016/06/06 15:29:10 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

/*
** -----===== Constructors =====-----
*/

t_gnode		*gnode_alloc(size_t type_size)
{
	t_gnode		*ans;

	if ((ans = (t_gnode *)malloc(type_size)))
	{
		ftl_init((t_list *)ans, type_size);
		ans->parent = NULL;
		ans->pos = NEW_VEC3(0, 0, 0);
		ans->alpha = 0;
		ans->beta = 0;
		ans->gamma = 0;
		ans->scale = 1;
		ans->is_obj = (type_size == sizeof(t_obj));
	}
	return (ans);
}

t_obj		*obj_alloc(char *str)
{
	t_obj	*ans;

	if ((ans = (t_obj *)gnode_alloc(sizeof(t_obj))))
	{
		ans->vertices = ft_dyna_new(sizeof(t_vrtx));
		ans->faces = ft_dyna_new(sizeof(t_face));
		if (ft_dyna_datainit(&ans->vertices) || ft_dyna_datainit(&ans->faces))
			ft_exit("obj_alloc", "Out of memory (malloc failed)");
		ans->name = ft_strdup(str);
		ans->dim = 0;
	}
	return (ans);
}

t_camera	*camera_alloc(void)
{
	t_camera *ans;

	if ((ans = (t_camera *)gnode_alloc(sizeof(t_camera))))
	{
		ans->fov = 60;
		ans->ratio = (t_pnt2i){16, 9};
	}
	return (ans);
}

t_obj		obj_new(char *str)
{
	t_obj	ans;

	ftl_init((t_list *)&ans.node, sizeof(t_obj));
	ans.node.parent = NULL;
	ans.node.pos = NEW_VEC3(0, 0, 0);
	ans.node.alpha = 0;
	ans.node.beta = 0;
	ans.node.gamma = 0;
	ans.node.scale = 1;
	ans.vertices = ft_dyna_new(sizeof(t_vrtx));
	ans.faces = ft_dyna_new(sizeof(t_vrtx));
	if (ft_dyna_datainit(&ans.vertices) || ft_dyna_datainit(&ans.faces))
		ft_exit("obj_new", "Out of memory (malloc failed)");
	if (!(ans.name = ft_strdup(str)))
		ft_putstr_fd("ERROR\tobj_new : Malloc failed\n", 2);
	ans.dim = 0;
	ans.node.is_obj = 1;
	return (ans);
}
