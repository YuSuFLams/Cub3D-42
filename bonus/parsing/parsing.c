/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 23:03:14 by ylamsiah          #+#    #+#             */
/*   Updated: 2024/01/03 14:10:56 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	load_image(t_cub3d *vars)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (!vars->direction[i])
			(ft_putstr_fd(ERR_PATH_DIRECTION, 2, RED), exit(1));
		vars->texture[i] = mlx_load_png(vars->direction[i]);
		if (!vars->texture[i])
			(ft_putstr_fd("ERROR: Could not load texture\n", 2, RED), exit(2));
		if (vars->texture[i]->height != vars->texture[i]->width)
			(ft_putstr_fd(ERR_PNG_SQUARE, 2, RED), exit(3));
	}
}

void	parsing(char *file_name, t_cub3d *vars)
{
	ft_bzero(vars, sizeof(t_cub3d));
	check_name_map(file_name);
	first_read_map(file_name, vars);
	set_direction(vars);
	map_no_white_space(vars->o_map);
	check_valid_map(vars);
	new_map_1(vars);
	vars->s = new_map(vars->n_map);
	vars->n_map = vars->s;
	vars->height = set_size_map(vars->n_map);
	vars->width = get_max(vars->n_map, set_size_map(vars->n_map));
	check_file(vars);
	load_image(vars);
}
