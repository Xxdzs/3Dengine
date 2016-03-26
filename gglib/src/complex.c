/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 18:26:09 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/26 23:05:52 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_cmplx		cmplx_log(t_cmplx *c)
{
	ensure_polar(c);
	return ((t_cmplx){{log(c->p.mod), c->p.arg}});
}

t_cmplx		cmplx_cos(t_cmplx *c)
{
	ensure_carth(c);
	return ((t_cmplx){{cos(c->c.x) * cosh(c->c.y), sin(c->c.x) * sinh(c->c.y)}});
}

t_cmplx		cmplx_sin(t_cmplx *c)
{
	ensure_carth(c);
	return ((t_cmplx){{sin(c->c.x) * cosh(c->c.y), cos(c->c.x) * sinh(c->c.y)}});
}
