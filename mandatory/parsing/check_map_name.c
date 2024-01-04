/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:35:28 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/12/16 00:54:44 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_name_map(char *map_name)
{
	int	i;

	i = ft_strlen(map_name);
	if (*(map_name + i - 1) != 'b' || *(map_name + i - 2) != 'u' || \
	*(map_name + i - 3) != 'c' || *(map_name + i - 4) != '.')
	{
		ft_putstr_fd("ERROR: Your Map Should End By ", 2, RED);
		ft_putstr_fd("(cub) \"./cub3d *.cub)\" !!.\n", 2, RED);
		exit (EXIT_FAILURE);
	}
}
