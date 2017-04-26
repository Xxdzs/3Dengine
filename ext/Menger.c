/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 21:41:02 by angagnie          #+#    #+#             */
/*   Updated: 2017/04/26 23:47:01 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef union		_cubeV
{
	unsigned	vertice[8];
	struct
	{
		unsigned left[4];
		unsigned right[4];
	};
}					cubeV;

typedef struct		_cube
{
	unsigned	faces;
	union
	{
		struct
		{
			cubeV		outer;
			cubeV		inner;
			unsigned	edges[3][8];
			unsigned	face[6][4];
		};
		unsigned		all[64];
	};
}					cube;

typedef struct		_pnt
{
	float		x;
	float		y;
	float		z;
}					pnt;

#define TOP 0x01
#define MD0 0x02
#define BTM 0x04
#define MD1 0x08
#define MD2 0x10
#define MD3 0x20
#define ALL 0x3f

uint8_t trans[][] = {{0,1,2,3,4,5,6,7},{1,0,4,5,2,3,7,6}};

#define vertex(x,y,z) printf("v %f %f");

void				menger(uint8_t depth, cubeV outer, unsigned faces)
{
	cube	c;

	c.outer = outer;
	c.faces = faces;
	(void)outer;
	(void)faces;
	if (depth == 1)
	{
		for (uint8_t f = 0 ; f < 6 ; f++)
			if (c.faces & (1 << f))

	}
}
