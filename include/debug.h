/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 00:44:56 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/24 00:58:45 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

void	db_putvalue(char const *str, int n);
void	db_putstr(char const *str);

# define DEBUG_INT(E) db_putvalue("The expression " #E " yields : ", E)

#endif
