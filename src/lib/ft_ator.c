/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 11:03:41 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/15 22:54:44 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "settings.h"
#include "libft.h"

t_real		ft_ator(char *str)
{
	t_real	ans;
	t_real	pow;
	int		positive;

	while (ft_isspace(*str))
		str++;
	positive = (*str == '-' ? 0 : 1);
	if (*str == '+' || *str == '-')
		str++;
	ans = 0;
	pow = 1;
	while (ft_isdigit(*str))
		ans = 10 * ans + (*str++ - '0');
	if (*str == '.')
		while (ft_isdigit(*++str))
			ans += (pow = pow / 10) * (*str - '0');
	return (positive ? ans : -ans);
}
