/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:36:08 by ylamsiah          #+#    #+#             */
/*   Updated: 2024/01/03 14:23:23 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	check_input(int ac)
{
	if (ac != 2)
	{
		ft_putstr_fd("\033[0;36mERROR:\033[0;32mINVALID ARGUMENTS!\n", 2, NULL);
		if (ac == 1)
		{
			ft_putstr_fd("\033[0;36mERROR:\033[0;32mToo few Args.\n", 2, NULL);
			exit (EXIT_FAILURE);
		}
		if (ac > 2)
		{
			ft_putstr_fd("\033[0;36mERROR:\033[0;32mToo Many Args.\n", 2, NULL);
			exit (EXIT_FAILURE);
		}
	}
}

int	main(int ac, char **str)
{
	t_cub3d		*vars;

	check_input(ac);
	vars = (t_cub3d *)malloc(sizeof(t_cub3d));
	if (!vars)
		(ft_putstr_fd(ERR_MEMORY, 2, RED), exit(EXIT_FAILURE));
	parsing(str[1], vars);
	set_map(vars);
	free_all(vars);
	return (0);
}
