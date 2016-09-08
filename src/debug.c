/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 00:23:12 by angagnie          #+#    #+#             */
/*   Updated: 2016/09/08 01:15:50 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

void	db_putstr(char const *str)
{
	ft_putendl(str);
}

void	db_putvalue(char *str, int n, char *end)
{
	ft_putstr(str);
	ft_putnbr(n);
	ft_putendl(end);
}

#else

void	db_putstr(char const *str)
{
	(void)str;
}

void	db_putvalue(char const *str, int n, char const *end)
{
	(void)str;
	(void)n;
	(void)end;
}

#endif
