/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 12:42:57 by angagnie          #+#    #+#             */
/*   Updated: 2016/06/12 12:56:30 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_cmplx		cmplx_square(t_cmplx *c)
{
	if (c->type == CARTHESIAN)
		return (NEW_CMPLX((XP(c) + YP(c)) * (XP(c) - YP(c)),
			2 * XP(c) * YP(c)));
	return ((t_cmplx){POLAR, {{MODP(c) * MODP(c), 2 * ARGP(c)}}});
}
