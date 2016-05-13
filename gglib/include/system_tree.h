/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:27:17 by angagnie          #+#    #+#             */
/*   Updated: 2016/05/13 15:05:56 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEM_TREE_H
# define SYSTEM_TREE_H

# include "libft.h"
# include "settings.h"
# include "geometry.h"

/*
** t_node <- t_list <- t_gnode <- t_obj
*/

/*
** pos : the node's origin seen by the parent
** rot : the rotation (and scale) transformming
** |		the child system into the parent's
*/

typedef struct	s_gnode
{
	t_list			children;
	struct s_gnode	*parent;
	t_vec3t			pos;
	t_real			scale;
# ifdef EULER
	t_real			alpha;
	t_real			beta;
	t_real			gamma;
# else
	t_qtrn			rot;
# endif
	int				is_obj;
}				t_gnode;

typedef struct	s_vrtx
{
	t_vec3t		vec;
	t_vec3t		normal;
}				t_vrtx;

typedef struct	s_face
{
	int		index[4];
}				t_face;

typedef struct	s_obj
{
	t_gnode		node;
	t_dyna		vertices;
	t_dyna		faces;
	char		*name;
	t_vec3t		*dim;
}				t_obj;

/*
** The camera should not be the child of any node,
** but have a parent : the world
** or any gnode for a relative POV
*/

typedef struct	s_camera
{
	t_gnode		node;
	t_pnt2i		ratio;
	int			fov;
}				t_camera;

typedef struct	s_grfx
{
	t_obj		*world;
	t_camera	*cam;
}				t_grfx;

/*
**	-----=====  Constructors  =====-----
*/

# define NEW_VRTX (t_vrtx){NEW_VEC3(0, 0, 0), NEW_VEC3(0, 0, 0)}

t_gnode			*gnode_alloc(size_t type_size);
t_obj			*obj_alloc(char *str);
t_obj			obj_new(char *str);
t_camera		*camera_alloc(void);

/*
**	-----=====  Destructors  =====-----
*/

void			obj_del(t_obj *subject);
void			obj_free(t_obj **subject);

/*
**	-----=====  Member Functions  =====-----
*/

void			gnode_add_child(t_gnode *parent, t_gnode *child);
int				obj_add_center(t_gnode *parent, t_obj *child);
t_obj			*obj_find(const t_obj *const node, const char *const name);

#endif
