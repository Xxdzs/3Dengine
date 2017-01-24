/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_tree_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <angagnie@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 14:10:06 by sid               #+#    #+#             */
/*   Updated: 2017/01/24 06:42:39 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system_tree.h"
#include "ggl.h"

/*
** -----===== Destructors =====-----
*/

void		obj_del(t_obj *subject)
{
	ftl_del((t_list *)&subject->node);
	fta_clear((t_array *)&subject->vertices);
	fta_clear((t_array *)&subject->faces);
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
