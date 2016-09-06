/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 19:15:59 by angagnie          #+#    #+#             */
/*   Updated: 2016/09/06 04:40:25 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

int		wolf_submain(t_env *w, int ac, char **av)
{
	ft_putstr("Wolf Sub-main\n");
	return (0);
}

int		editor_submain(t_env *w, int ac, char **av)
{
	ft_putstr("Editor Sub-main\n");
	return (0);
}

#ifdef DEBUG

int		the_main(int ac, char **av)
{
	if (ac == 0)
		ft_putstr("Missing arguments !!\n");
	else if (!ft_strcmp("editor", *av))
	{
		ft_putstr("Editing campaign ");
		if (ac > 2)
			ft_putendl(av[1]);
		else
			ft_putendl("Tests");
		ggl_main(ac, av, &editor_submain);
	}
	else
		ggl_main(ac, av, &wolf_submain);
	return (0);
}

#else

int		the_main(int ac, char **av)
{
	if (ac == 0)
		ft_putstr("Usage :\t./wolf3d _name_\n\tto load maps/WLF/_name_[00-99].wlf\n");
	else if (!ft_strcmp("editor", *av))
		ggl_main(ac, av, &editor_submain);
	else
		ggl_main(ac, av, &wolf_submain);
	return (0);
}

#endif
