/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_tree_misc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <angagnie@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 14:10:06 by sid               #+#    #+#             */
/*   Updated: 2016/06/03 16:14:57 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

void	vrtx_transform(const t_mat3x3 *m, t_vrtx *v)
{
	v->vec.v = mat_3x3_times_3x1(m, &(v->vec.v));
}

t_obj       *obj_find(const t_node *const node, const char *const name)
{
    t_node  *tmp;
    t_obj   *ans;

    if (node.is_obj && ((t_obj *)node)->name && name && ft_strcmp(((t_obj *)node)->name, name) == 0)
        return ((t_obj *)node);
    if (node->children.size > 0)
    {
        tmp = &(node->children.root);
        while ((tmp = tmp->next) != &(node->children.root))
            if ((ans = obj_find(tmp, name)) != NULL)
                return (ans);
    }
    return (NULL);
}
