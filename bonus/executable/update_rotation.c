/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:10:51 by abelkace          #+#    #+#             */
/*   Updated: 2024/01/03 16:08:28 by ylamsiah         ###   ########.fr       */
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

void	mouse(t_cub3d *vars)
{
	int			mouse_x_before;
	static int	x_mouse;

	vars->mouse.y = 0;
	mouse_x_before = x_mouse;
	mlx_get_mouse_pos(vars->mlx, &vars->mouse.x, &vars->mouse.y);
	if (vars->mouse.x < 0 || vars->mouse.x > WINDOW_WIDTH \
	|| vars->mouse.y < 0 || vars->mouse.y > WINDOW_HEIGHT)
		return ;
	if (vars->mouse.x == mouse_x_before)
		return ;
	if (vars->mouse.x > mouse_x_before)
		vars->rotation_angle += 0.1;
	if (vars->mouse.x < mouse_x_before)
		vars->rotation_angle -= 0.1;
	vars->rotation_angle = ft_normalize_angle(vars->rotation_angle);
	x_mouse = vars->mouse.x;
}
