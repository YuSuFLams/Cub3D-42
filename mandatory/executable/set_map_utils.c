/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:52:20 by abelkace          #+#    #+#             */
/*   Updated: 2024/01/01 21:50:19 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	ft_normalize_angle(double angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

float	get_xx(t_cub3d *vars)
{
	float	xx;

	if (vars->wall_up_left)
	{
		if (vars->wall_down)
			vars->hes = vars->texture[0];
		else
			vars->hes = vars->texture[1];
		xx = fmod(vars->wall_hit_x, TILE_SIZE) \
		* (vars->hes->width) / TILE_SIZE;
	}
	else
	{
		if (vars->wall_left)
			vars->hes = vars->texture[2];
		else
			vars->hes = vars->texture[3];
		xx = fmod(vars->wall_hit_y, TILE_SIZE) \
		* (vars->hes->width) / TILE_SIZE;
	}
	return (xx);
}

void	ft_rectangle(t_cub3d *vars, int x, int y, int height)
{
	int				i;
	int				j;
	double			xx;
	float			yy;

	i = x - 1;
	while (++i < x + WALL_STRIP_WIDTH)
	{
		j = 0;
		while (j < WINDOW_HEIGHT)
		{
			if (j >= 0 && j < y)
				mlx_putpixel(vars->img, i, j, put_color_ceiling(vars));
			else if (j >= y && j < (y + height))
			{
				xx = get_xx(vars);
				yy = vars->hes->height * ((float)(j - y)) / height;
				mlx_putpixel(vars->img, i, j, \
				get_color_from_image(vars->hes, xx, yy));
			}
			else if (j >= (y + height) && j < WINDOW_HEIGHT)
				mlx_putpixel(vars->img, i, j, put_color_floor(vars));
			j++;
		}
	}
}

void	ft_draw(t_cub3d *vars)
{
	double	ray_angle;
	int		i;
	int		wall_height;
	float	ray_distance;
	float	projection_plane;

	i = -1;
	ray_angle = vars->rotation_angle - ((vars->fov) / 2);
	while (++i < vars->num_rays)
	{
		ray_angle = ft_normalize_angle(ray_angle);
		ft_cast_ray(vars, i, ray_angle);
		ray_distance = vars->rays[i] * cos (ray_angle - vars->rotation_angle);
		if (!ray_distance)
			ray_distance = 1;
		projection_plane = (WINDOW_WIDTH / 2) / tan((vars->fov) / 2);
		wall_height = (int)((TILE_SIZE / ray_distance) \
		* projection_plane);
		ft_rectangle(vars, (i * WALL_STRIP_WIDTH), ((WINDOW_HEIGHT / 2) \
		- (wall_height / 2)), wall_height);
		ray_angle += vars->fov / vars->num_rays;
	}
	mlx_image_to_window(vars->mlx, vars->img, 0, 0);
}
