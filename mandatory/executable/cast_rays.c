/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 22:01:55 by abelkace          #+#    #+#             */
/*   Updated: 2024/01/01 02:49:00 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_next_step_hor(t_cub3d *vars, double ray_angle)
{
	vars->y_intercept = floor(vars->pos.y / TILE_SIZE) * TILE_SIZE;
	if (vars->is_up == 0)
		vars->y_intercept += TILE_SIZE;
	vars->x_intercept = vars->pos.x + ((vars->y_intercept - \
	vars->pos.y) / tan(ray_angle));
	vars->y_step = TILE_SIZE;
	if (vars->is_up == 1)
		vars->y_step *= -1;
	vars->x_step = TILE_SIZE / tan(ray_angle);
	if (vars->is_left == 1 && vars->x_step > 0)
		vars->x_step *= -1;
	else if (vars->is_left == 0 && vars->x_step < 0)
		vars->x_step *= -1;
	vars->next_hor_inter_x = vars->x_intercept;
	vars->next_hor_inter_y = vars->y_intercept;
}

void	check_hor(t_cub3d *vars, double ray_angle)
{
	vars->found_hor_hit = 0;
	ft_directions(vars, ray_angle);
	get_next_step_hor(vars, ray_angle);
	while (vars->next_hor_inter_x >= 0 && vars->next_hor_inter_x < \
	vars->window_width && vars->next_hor_inter_y >= 0 && \
	vars->next_hor_inter_y < vars->window_height)
	{
		if (vars->n_map[(int)((vars->next_hor_inter_y - vars->is_up) / \
		TILE_SIZE)][(int)(vars->next_hor_inter_x / TILE_SIZE)] == '1')
		{
			vars->found_hor_hit = 1;
			vars->hor_wallhitx = vars->next_hor_inter_x;
			vars->hor_wallhity = vars->next_hor_inter_y;
			break ;
		}
		else
		{
			vars->next_hor_inter_x += vars->x_step;
			vars->next_hor_inter_y += vars->y_step;
		}
	}
}

void	get_next_step_ver(t_cub3d *vars, double ray_angle)
{
	vars->x_intercept = floor(vars->pos.x / TILE_SIZE) * TILE_SIZE;
	if (vars->is_left == 0)
		vars->x_intercept += TILE_SIZE;
	vars->y_intercept = vars->pos.y + ((vars->x_intercept - \
	vars->pos.x) * tan(ray_angle));
	vars->x_step = TILE_SIZE;
	if (vars->is_left == 1)
		vars->x_step *= -1;
	vars->y_step = TILE_SIZE * tan(ray_angle);
	if (vars->is_up == 1 && vars->y_step > 0)
		vars->y_step *= -1;
	else if (vars->is_up == 0 && vars->y_step < 0)
		vars->y_step *= -1;
	vars->next_ver_inter_x = vars->x_intercept;
	vars->next_ver_inter_y = vars->y_intercept;
}

void	check_ver(t_cub3d *vars, double ray_angle)
{
	vars->found_ver_hit = 0;
	vars->ver_wallhitx = 0;
	vars->ver_wallhity = 0;
	get_next_step_ver(vars, ray_angle);
	while (vars->next_ver_inter_x >= 0 && vars->next_ver_inter_x \
	< vars->window_width && vars->next_ver_inter_y >= 0 && \
	vars->next_ver_inter_y < vars->window_height)
	{
		if (vars->n_map[(int)(vars->next_ver_inter_y / TILE_SIZE)] \
		[(int)((vars->next_ver_inter_x - vars->is_left) / TILE_SIZE)] == '1')
		{
			vars->found_ver_hit = 1;
			vars->ver_wallhitx = vars->next_ver_inter_x;
			vars->ver_wallhity = vars->next_ver_inter_y;
			break ;
		}
		else
		{
			vars->next_ver_inter_x += vars->x_step;
			vars->next_ver_inter_y += vars->y_step;
		}
	}
}

void	ft_cast_ray(t_cub3d *vars, int i, double ray_angle)
{
	check_hor(vars, ray_angle);
	check_ver(vars, ray_angle);
	if (vars->found_hor_hit == 1)
		vars->hor_distance = get_distance(vars, vars->hor_wallhitx, \
		vars->hor_wallhity);
	else
		vars->hor_distance = INT_MAX;
	if (vars->found_ver_hit == 1)
		vars->ver_distance = get_distance(vars, vars->ver_wallhitx, \
		vars->ver_wallhity);
	else
		vars->ver_distance = INT_MAX;
	if (vars->ver_distance < vars->hor_distance)
	{
		vars->rays[i] = vars->ver_distance;
		vars->wall_hit_x = vars->ver_wallhitx;
		vars->wall_hit_y = vars->ver_wallhity;
	}
	else
	{
		vars->rays[i] = vars->hor_distance;
		vars->wall_hit_x = vars->hor_wallhitx;
		vars->wall_hit_y = vars->hor_wallhity;
	}
	put_variable(vars);
}
