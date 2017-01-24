/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 00:23:12 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/24 01:01:17 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

void	db_putstr(char const *str)
{
	ft_putendl(str);
}

void	db_putvalue(char const *str, int n)
{
	ft_putstr(str);
	ft_putnbr(n);
	ft_putchar('\n');
}

#else

void	db_putstr(char const *str)
{
	(void)str;
}

void	db_putvalue(char const *str, int n)
{
	(void)str;
	(void)n;
}

#endif
