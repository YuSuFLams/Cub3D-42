/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 01:39:56 by ylamsiah          #+#    #+#             */
/*   Updated: 2024/01/01 18:26:29 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	check_wall_collisions_hor(t_cub3d *vars, int x, int y)
{
	if (vars->n_map[(int)y / TILE_SIZE] \
	[(int)(vars->pos.x) / TILE_SIZE] == '1')
		return (false);
	else if (vars->n_map[(int)vars->pos.y / TILE_SIZE] \
	[(int)x / TILE_SIZE] == '1' )
		return (false);
	return (true);
}

static bool	check_wall_collisions_ver(t_cub3d *vars, int x, int y)
{
	if (vars->n_map[(int)y / TILE_SIZE] \
	[(int)(vars->pos.x) / TILE_SIZE] == '1')
		return (false);
	else if (vars->n_map[(int)vars->pos.y / TILE_SIZE] \
	[(int)x / TILE_SIZE] == '1')
		return (false);
	return (true);
}

void	updated_map_up_down(t_cub3d *vars)
{
	float	movestep;
	float	x;
	float	y;

	x = vars->pos.x;
	y = vars->pos.y;
	movestep = vars->up_down_moves * vars->move_speed;
	vars->rotation_angle += (vars->right_left_moves * vars->rotation_speed);
	x += movestep * cos(vars->rotation_angle);
	y += movestep * sin(vars->rotation_angle);
	if (x >= 0 && (int)x <= (vars->width * TILE_SIZE) && \
		vars->n_map[(int)y / TILE_SIZE][(int)x / TILE_SIZE] != '1' && \
		y >= 0 && (int)y <= (vars->height * TILE_SIZE))
	{
		if (!check_wall_collisions_hor(vars, x, y))
			return ;
		vars->pos.x = x;
		vars->pos.y = y;
	}
	else
		return ;
}

void	updated_map_right_left(t_cub3d *vars)
{
	float	movestep;
	float	x;
	float	y;

	x = vars->pos.x;
	y = vars->pos.y;
	movestep = vars->right_left_moves * vars->move_speed;
	vars->rotation_angle += (vars->up_down_moves * vars->rotation_speed);
	x += movestep * cos(vars->rotation_angle + (M_PI / 2));
	y += movestep * sin(vars->rotation_angle + (M_PI / 2));
	if (x >= 0 && (int)x <= (vars->width * TILE_SIZE) && \
		vars->n_map[(int)y / TILE_SIZE][(int)x / TILE_SIZE] != '1' && \
		y >= 0 && (int)y <= (vars->height * TILE_SIZE))
	{
		if (!check_wall_collisions_ver(vars, x, y))
			return ;
		vars->pos.x = x;
		vars->pos.y = y;
	}
	else
		return ;
}
