/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 05:18:16 by angagnie          #+#    #+#             */
/*   Updated: 2016/09/06 08:03:30 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

typedef enum	e_block
{
	NONE = 0,
	FLOOR,
	CEIL,
	BOTH,
	PREV,
	NEXT = 8,

	CEILING = CEIL,
	FLOOR_CEILING = BOTH,
	CEILING_FLOOR = BOTH,
	PREVIOUS = PREV
}				t_block;

typedef struct	s_cell
{
	char		wall;
	t_block		block;
	// Textures
}				t_cell;

typedef struct	s_edtr
{
	size_t		tile;
}				t_edtr;

#endif
