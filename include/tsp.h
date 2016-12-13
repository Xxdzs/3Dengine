/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 20:14:25 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/09 17:15:38 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TSP_H
# define TSP_H

# include "ggl.h"

/*
** Travel Salesman Problem
** t_tsp -extends-> t_env
*/

typedef struct		s_city
{
	t_pnt2i		pos;
	char		*name;
}

/*
** Array<City> cities;
*/

typedef struct		s_tsp
{
	t_env		super;
	int			n;
	int			*t;
	t_array		city;
}					t_tsp;

#endif
