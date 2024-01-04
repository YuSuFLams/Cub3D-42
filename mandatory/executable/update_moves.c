/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:00:04 by abelkace          #+#    #+#             */
/*   Updated: 2024/01/01 02:49:39 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_up(t_cub3d *vars)
{
	vars->up_down_moves = 1;
	updated_map_up_down(vars);
}

void	ft_down(t_cub3d *vars)
{
	vars->up_down_moves = -1;
	updated_map_up_down(vars);
}

void	ft_left(t_cub3d *vars)
{
	vars->right_left_moves = -1;
	updated_map_right_left(vars);
}

void	ft_right(t_cub3d *vars)
{
	vars->right_left_moves = 1;
	updated_map_right_left(vars);
}
