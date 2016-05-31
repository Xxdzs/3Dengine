/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_tree_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <angagnie@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 14:10:06 by sid               #+#    #+#             */
/*   Updated: 2016/05/31 17:35:17 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

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
