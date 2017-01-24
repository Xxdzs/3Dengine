/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easings.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 05:50:49 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/24 07:44:35 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASINGS_H
# define EASINGS_H

int		identity(int const i, int const dout, const int din);
int		linear_interpolation(int const i, int const dout, int const din);
int		ease_out_sine(int const i, int const dout, int const din);
int		ease_inout_sine(int const i, int const dout, int const din);

#endif
