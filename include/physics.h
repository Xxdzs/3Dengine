/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 18:19:00 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/24 18:49:55 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHYSICS_H
# define PHYSICS_H

# include "libft.h"
# include "geometry.h"

typedef struct		s_physical
{
	t_vec3t		position;
	t_vec3t		speed;
	t_vec3t		acceleration;
}					t_physical;

# define NEW_PHYSICAL (t_physical){THRICE(NEW_VEC3(0,0,0))}

#endif
