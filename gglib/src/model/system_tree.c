/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <sid@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 14:10:06 by sid               #+#    #+#             */
/*   Updated: 2016/04/25 01:44:34 by angagnie         ###   ########.fr       */
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
		ans->rot = NEW_QTRN(0, 0, 0, 1);
		ans->scale = 1;
	}
	return (ans);
}

t_obj		*obj_alloc(char *str)
{
	t_obj	*ans;

	if ((ans = (t_obj *)gnode_alloc(sizeof(t_obj))))
	{
		ans->vertices = ft_dyna_new(sizeof(t_vrtx));
		ft_dyna_datainit(&ans->vertices);
		ans->faces = ft_dyna_new(sizeof(t_face));
		ft_dyna_datainit(&ans->faces);
		ans->name = ft_strdup(str);
		ans->dim = 0;
	}
	return (ans);
}

t_camera	*camera_alloc(void)
{
	t_camera *ans;

	if ((ans = (t_camera *)gnode_alloc(sizeof(t_obj))))
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
	ans.node.rot = NEW_QTRN(0, 0, 0, 0);
	ans.node.scale = 1;
	ans.vertices = ft_dyna_new(sizeof(t_vrtx));
	ft_dyna_datainit(&ans.vertices);
	ans.faces = ft_dyna_new(sizeof(t_vrtx));
	ft_dyna_datainit(&ans.faces);
	if (!(ans.name = ft_strdup(str)))
	{
		write(2, "obj_new : Malloc failed -> Exiting\n", 35);
		exit(1);
	}
	ans.dim = 0;
	return (ans);
}

/*
** -----===== Destructors =====-----
*/

void		obj_del(t_obj *subject)
{
	ftl_del((t_list *)&subject->node);
	ft_dyna_del((t_dyna *)&subject->vertices);
	ft_dyna_del((t_dyna *)&subject->faces);
	if (subject->name)
		free(subject->name);
	if (subject->dim)
		free(subject->dim);
}

void		obj_free(t_obj **subject)
{
	obj_del(*subject);
	free(*subject);
	*subject = NULL;
}

/*
** -----===== Member Functions =====-----
*/

void		gnode_add_child(t_gnode *parent, t_gnode *child)
{
	child->parent = parent;
	ftl_push_back((t_list *)parent, (t_node *)child);
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

t_obj		*gnode_find(const t_obj *const node, const char *const name)
{
	t_node	*tmp;
	t_gnode	*ans;

	if (node->name && name && ft_strcmp(node->name, name) == 0)
		return ((t_obj *)node);
	if (node->node.children.size > 0)
	{
		tmp = (t_node *)&(node->node.children);
		while ((tmp = tmp->next) != node->node.children.root.next)
			if ((ans = gnode_find((t_obj *)tmp, name)) != NULL)
				return (ans);
	}
	return (NULL);
}
