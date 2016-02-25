/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:27:17 by angagnie          #+#    #+#             */
/*   Updated: 2016/02/25 18:58:20 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEM_TREE_H
# define SYSTEM_TREE_H

/*
** pos : the node's origin seen by the parent
** rot : the rotation (and scale) transformming
** |		the child system into the parent's
*/

typedef struct	s_gnode
{
	struct s_gnode	*parent;
	t_list			children;
	t_vec3			pos;
	t_qtrn			rot;
}				t_gnode;

typedef struct	s_obj
{
	t_gnode			node;
	t_dyna			vertices;
	t_dyna			faces;
}				t_obj;

/*
** The camera should not be the child of any node,
** but can have a parent for a relative POV
*/

typedef struct	s_camera
{
	t_gnode		node;
	t_pnt2i		ratio;
	int			fov;
}				t_camera;

#endif
