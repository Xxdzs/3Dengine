/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 15:10:35 by angagnie          #+#    #+#             */
/*   Updated: 2016/05/13 15:49:04 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*const ans = malloc(count * size);

	if (ans == NULL)
		write(2, "ERROR\tft_calloc : Malloc failed\n", 14);
	else
		ft_bzero(ans, size * count);
	return (ans);
}

void	ft_exit(char const *const fnc, char const *const str)
{
	ft_putstr_fd(2, "ERROR\tCritical failure in function ");
	ft_putstr_fd(2, fnc);
	ft_putstr_fd(2, ". The program will exit, reason being : ");
	ft_putstr_fd(2, str);
	ft_putstr_fd(2, ".\n");
	exit(1);
}

void	*ft_safe_calloc(size_t count, size_t size)
{
	void	*const ans = malloc(count * size);

	if (ans == NULL)
		ft_exit("ft_safe_calloc", "Out of memory (Malloc failed)");
	ft_bzero(ans, count * size);
	return (ans);
}
