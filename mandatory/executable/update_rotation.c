/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:10:51 by abelkace          #+#    #+#             */
/*   Updated: 2024/01/03 10:53:11 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_rotate_right(t_cub3d *vars)
{
	vars->right_left_moves = 1;
	updated_map_up_down(vars);
}

void	ft_rotate_left(t_cub3d *vars)
{
	vars->right_left_moves = -1;
	updated_map_up_down(vars);
}
