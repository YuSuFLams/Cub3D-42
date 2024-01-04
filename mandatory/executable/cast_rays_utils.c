/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 02:29:28 by ylamsiah          #+#    #+#             */
/*   Updated: 2024/01/01 02:48:52 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	get_distance(t_cub3d *vars, float xa, float ya)
{
	return (sqrt(((vars->pos.x - xa) * (vars->pos.x - xa)) \
	+ ((vars->pos.y - ya) * (vars->pos.y - ya))));
}

void	ft_directions(t_cub3d *vars, double ray_angle)
{
	if (ray_angle >= 0 && ray_angle <= M_PI)
		vars->is_up = 0;
	else
		vars->is_up = 1;
	if (ray_angle <= 0.5 * M_PI || ray_angle >= 1.5 * M_PI)
		vars->is_left = 0;
	else
		vars->is_left = 1;
}

void	put_variable(t_cub3d *vars)
{
	if (vars->ver_distance > vars->hor_distance)
		vars->wall_up_left = 1;
	else
		vars->wall_up_left = 0;
	vars->wall_down = vars->is_up;
	vars->wall_left = vars->is_left;
}
