/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:27:17 by angagnie          #+#    #+#             */
/*   Updated: 2016/02/22 18:04:58 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEM_TREE_H
# define SYSTEM_TREE_H

/*
** pos : the node's origin seen by the father
** rot :
*/

typedef struct	s_gnode
{
	struct s_gnode	father;
	t_list			sons;
	t_qtrn			first_rot;
	t_vec3			pos;
	t_qtrn			second_rot;
	t_dyna			vertices;
}				t_gnode;

/*
** The camera should not be the son of any node,
** but can have a father for a relative POV
*/

typedef struct	s_camera
{
	t_gnode		node;

}				t_camera;

#endif
