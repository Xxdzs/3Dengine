/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menger2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 22:23:47 by angagnie          #+#    #+#             */
/*   Updated: 2017/04/26 16:04:45 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct	_pnt
{
	float	x;
	float	y;
}				pnt;

typedef struct	_corner
{
	unsigned	lu;
	unsigned	ru;
	unsigned	ld;
	unsigned	rd;
}				corner;

#define vertex(X, Y)						\
	printf("v %f %f 0\n", X, Y);			\
	(*i)++;

#define	face(LU, RU, LD, RD)						\
	dprintf(2, "f %i %i %i %i\n", LD, LU, RU, RD);

void		sierpinski(pnt p, float d, corner c, unsigned depth, unsigned* i)
{
	unsigned j = *i;

	if (depth == 1)
	{
		// define the 4 inner points
		vertex(p.x + d/3, p.y + d/3);
		vertex(p.x + 2*d/3, p.y + d/3);
		vertex(p.x + d/3, p.y + 2*d/3);
		vertex(p.x + 2*d/3, p.y + 2*d/3);
		// define 4 trapezes
		face(c.lu, j+1, c.ld, j+3);
		face(c.lu, c.ru, j+1, j+2);
		face(j+2, c.ru, j+4, c.rd);
		face(j+3, j+4, c.ld, c.rd);
	}
	else
	{
		// define 12 points
		vertex(p.x + d/3,		p.y);
		vertex(p.x + 2*d/3,		p.y);
		vertex(p.x,				p.y + d/3);
		vertex(p.x + d/3,		p.y + d/3);
		vertex(p.x + 2*d/3,		p.y + d/3);
		vertex(p.x + d,			p.y + d/3);
		vertex(p.x,				p.y + 2*d/3);
		vertex(p.x + d/3,		p.y + 2*d/3);
		vertex(p.x + 2*d/3,		p.y + 2*d/3);
		vertex(p.x + d,			p.y + 2*d/3);
		vertex(p.x + d/3,		p.y + d);
		vertex(p.x + 2*d/3,		p.y + d);
		// recusrive calls in the 8 sub squares
		sierpinski(p, d/3, (corner){c.lu, j+1, j+3, j+4}, depth - 1, i);
		sierpinski((pnt){p.x + d/3, p.y}, d/3, (corner){j+1, j+2, j+4, j+5}, depth - 1, i);
		sierpinski((pnt){p.x + 2*d/3, p.y}, d/3, (corner){j+2, c.ru, j+5, j+6}, depth - 1, i);
		sierpinski((pnt){p.x, p.y + d/3}, d/3, (corner){j+3, j+4, j+7, j+8}, depth - 1, i);
		sierpinski((pnt){p.x + 2*d/3, p.y + d/3}, d/3, (corner){j+5, j+6, j+9, j+10}, depth - 1, i);
		sierpinski((pnt){p.x, p.y + 2*d/3}, d/3, (corner){j+7, j+8, c.ld, j+11}, depth - 1, i);
		sierpinski((pnt){p.x + d/3,	p.y + 2*d/3}, d/3, (corner){j+8, j+9, j+11, j+12}, depth - 1, i);
		sierpinski((pnt){p.x + 2*d/3, p.y + 2*d/3}, d/3, (corner){j+9, j+10, j+12, c.rd}, depth - 1, i);
	}
}

int		main(int ac, char **av)
{
	unsigned	j = 0;
	unsigned	*i = &j;
	int			depth = 4;

	if (ac > 1)
		depth = atoi(av[1]);
	vertex(0.,0.);
	vertex(1.,0.);
	vertex(0.,1.);
	vertex(1.,1.);
	sierpinski((pnt){0,0}, 1., (corner){1,2,3,4}, depth, i);
	return (0);
}
