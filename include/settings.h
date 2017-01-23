/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 11:07:04 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/24 00:19:29 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

/*
** float, double or long double
** speed <----------> precision
** (and lightweight)
*/

typedef double	t_real;

# define DEFAULT_FOV 60
# define DEFAULT_RESOLUTION 1920, 1080
# define EULER
# define OPENCL

# define SUPPORTED_FORMATS SUPPORT(fdf),SUPPORT(obj)

int		parse_obj();
int		parse_fdf();

# define SUPPORT(F) #F,&parse_##F

#endif
